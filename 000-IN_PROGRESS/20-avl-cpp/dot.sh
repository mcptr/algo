#!/bin/sh


TMPDIR=.ignore/img
IMGSTAMP=$(date +'%Y%m%d-%H.%M-%s')
GRAPH_TXT=${1:-graph.viz.txt}
GRAPH_PNG=${2:-"$TMPDIR/graph-$IMGSTAMP.png"}

echo "Storing png as: $GRAPH_PNG"
VIEWER=${VIEWER:-qiv}

mkdir -p "$TMPDIR"
test -f $GRAPH_TXT || (echo "Missing: $GRAPH_TXT" && exit 1)
dot -Tpng -o $GRAPH_PNG $GRAPH_TXT; $VIEWER $GRAPH_PNG
