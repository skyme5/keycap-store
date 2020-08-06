#!/usr/bin/env ruby
# frozen_string_literal: true

require 'tty-table'

ROOT = 'A:/Logs/Keys'

keys_stat = {}

Dir.glob(File.join(ROOT, '**', '*.log')).each do |file|
  File.read(file, encoding: 'utf-8').encode('utf-8', invalid: :replace, undef: :replace, replace: '').split("\n").each do |line|
    timestamp, key, title = line.split('|')
    next if timestamp == 'KEY' || key.nil?

    key.strip!

    keys_stat[key] = 0 unless keys_stat.key?(key)
    keys_stat[key] += 1
  end
end

statistics = keys_stat.map { |k, v| [k, v] }
total = statistics.map { |e| e[1] }.sum
statistics.map! { |e| e << (e[1] * 100.0 / total).round(2) }
statistics.sort_by! {|e| e[2]}
statistics << ['Total', total, '100.00']

table = TTY::Table.new ['Key', 'Count', '%'], statistics.reverse
puts table.render
