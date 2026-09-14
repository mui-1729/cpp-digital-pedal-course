#!/usr/bin/env bash
set -euo pipefail

if [[ $# -lt 1 ]]; then
  echo "usage: $0 LESSON_NUMBER [starter|solution]"
  exit 1
fi

num=$(printf "%02d" "$((10#$1))")
mode=${2:-starter}
root="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
dir=$(find "$root/lessons" -maxdepth 1 -type d -name "${num}-*" | head -n1)

if [[ -z "$dir" ]]; then
  echo "lesson not found: $num"
  exit 1
fi

target="$dir/$mode"
if [[ ! -d "$target" ]]; then
  echo "$mode code is not provided for this lesson. Read: $dir/README.md"
  exit 1
fi

if [[ -f "$target/Makefile" ]]; then
  make -C "$target" clean app
  "$target/app"
else
  g++ -std=c++20 -Wall -Wextra -Wpedantic "$target/main.cpp" -o /tmp/pedal-course-app
  (cd /tmp && /tmp/pedal-course-app)
fi
