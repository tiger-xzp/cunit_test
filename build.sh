curDir=$(cd "$(dirname "$0")";pwd)

gcc  $CFLAGS -o basic_test max.c basic_main.c  -I ./CUnit/include $curDir/CUnit/lib/libcunit.a

gcc  $CFLAGS -o auto_test max.c auto_test.c  -I ./CUnit/include $curDir/CUnit/lib/libcunit.a

gcc  $CFLAGS -o console_test max.c console_test.c  -I ./CUnit/include $curDir/CUnit/lib/libcunit.a

#run unit test
./basic_test
./auto_test
./console_test