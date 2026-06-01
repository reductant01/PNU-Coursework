#!/bin/bash

testuser="cse"
if [ "$USER" \> "$testuser" ]; then
  echo "Welcome, $USER!"
else
  echo "Access denied. You are not $testuser."
fi
