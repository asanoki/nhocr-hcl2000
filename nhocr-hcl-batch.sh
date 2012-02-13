#!/bin/bash

if [ $# -eq 0 ] ; then
	echo "Usage: ./nhocr-hcl-batch.sh <first-hcl-file> [<second-hcl-file> ...] "
	exit -1
fi

for FILE in "$@"
do
	BASENAME=$(basename $FILE)
	NAME=${BASENAME%.*}
	echo "Converting $FILE to $NAME.img..."
	./nhocr-hcl $FILE $NAME.img
done
