#!/usr/bin/env bash

set -e

[ -z "$BUILD_DIR" ] && export BUILD_DIR=tmp
export PORT=$(( RANDOM + 1001 ))

if [ -n "$1" ]; then MAKE="$1"
elif [ -x "$(command -v gmake)" ]; then MAKE=gmake
else MAKE=make
fi

MAIN=./main
if [ "$2" = "--valgrind" ] || [ "$2" = '-v' ]; then
	MAIN="valgrind --leak-check=full $MAIN"
fi

$MAKE || exit 1

(
	cd $BUILD_DIR
	$MAIN $PORT >/dev/null &
	# shellcheck disable=SC2064
	trap "kill $!" EXIT
	sleep 1
	bats "$OLDPWD/test.bats"
)

find . -name '*.sh' -exec shellcheck {} +
