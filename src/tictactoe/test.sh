# Set Colors
if which tput >/dev/null 2>&1; then
  ncolors=$(tput colors)
fi
if [ -t 1 ] && [ -n "$ncolors" ] && [ "$ncolors" -ge 8 ]; then
  RED="$(tput setaf 1)"
  GREEN="$(tput setaf 2)"
  YELLOW="$(tput setaf 3)"
  BLUE="$(tput setaf 4)"
  LILA="$(tput setaf 5)"
  BOLD="$(tput bold)"
  NORMAL="$(tput sgr0)"
else
  RED=""
  GREEN=""
  YELLOW=""
  BLUE=""
  BOLD=""
  NORMAL=""
fi

ARROW="${BLUE}======>${NORMAL}"
ERROR="${RED}ERROR:${NORMAL}"
WARNING="${LILA}Warning:${NORMAL}"
FAILED=0
TESTS=4

printf "$ARROW Starting Tests for 3x3w3\n"
printf "$ARROW ${GREEN}Testing COL win Validation\n"
./tictactoe < ./tests/3x3w3COL.txt > /dev/null 2>&1
if [ $? -eq 139 ];
then
  printf "$ARROW $ERROR Error Segfaulted\n"
  ((FAILED++))
fi
printf "$ARROW ${GREEN}Testing ROW win Validation\n"
./tictactoe < ./tests/3x3w3ROW.txt > /dev/null 2>&1
if [ $? -eq 139 ];
then
  printf "$ARROW $ERROR Error Segfaulted\n"
  ((FAILED++))
fi
printf "$ARROW ${GREEN}Testing Left to Right Win Validation\n"
./tictactoe < ./tests/3x3w3DIAG_LR.txt > /dev/null 2>&1
if [ $? -eq 139 ];
then
  printf "$ARROW $ERROR Error Segfaulted\n"
  ((FAILED++))
fi
printf "$ARROW ${GREEN}Testing Right to Left Win Validation\n"
./tictactoe < ./tests/3x3w3DIAG_RL.txt > /dev/null 2>&1
if [ $? -eq 139 ];
then
  printf "$ARROW $ERROR Error Segfaulted\n"
  ((FAILED++))
fi
printf "$ARROW ${GREEN}Testing NoWinner\n"
./tictactoe < ./tests/3x3w3NoWinner.txt > /dev/null 2>&1
if [ $? -eq 139 ];
then
  printf "$ARROW $ERROR Error Segfaulted\n"
  ((FAILED++))
fi
printf "$ARROW ${GREEN}Testing Validation and Options\n"
./tictactoe < ./tests/3x3w3Options.txt > /dev/null 2>&1
if [ $? -eq 139 ];
then
  printf "$ARROW $ERROR Error Segfaulted\n"
  ((FAILED++))
fi

if [ $FAILED -gt 0 ]; then
  printf "$ARROW $WARNING $FAILED Tests Failed out of $TESTS\n"
else
  printf "$ARROW ${GREEN}All tests Complete without Errors\n"
fi
