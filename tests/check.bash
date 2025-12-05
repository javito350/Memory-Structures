touch tests/outputs
if grep -Pq "$3 = 0x47" "tests/log"; then echo "FIRST LIST LEN: TRUE" > tests/outputs; else : ; fi
if grep -Pq "$4 = 0x238" "tests/log"; then echo "FIRST LIST SIZE: TRUE" >> tests/outputs; else : ; fi
if grep -Pq "$7 = 0x17" "tests/log"; then echo "SECOND LIST LEN: TRUE" >> tests/outputs; else : ; fi
if grep -Pq "$8 = 0xb8" "tests/log"; then echo "SECOND LIST SIZE: TRUE" >> tests/outputs; else : ; fi
rm -rf tests/log