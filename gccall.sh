#! /bin/sh

BASEDIR=$(dirname "$0")
gcc $BASEDIR/OSMP/OSMPExecutable/osmpexecutable.c $BASEDIR/OSMP/OSMPLib/osmplib.c -o $BASEDIR/OSMP/OSMPExecutable/osmpexecutable
gcc $BASEDIR/OSMP/OSMPExecutable/osmpbarriertest.c $BASEDIR/OSMP/OSMPLib/osmplib.c -o $BASEDIR/OSMP/OSMPExecutable/osmpbarrier
gcc $BASEDIR/OSMP/OSMPExecutable/osmpbcast.c $BASEDIR/OSMP/OSMPLib/osmplib.c -o $BASEDIR/OSMP/OSMPExecutable/osmpbcast
gcc $BASEDIR/OSMP/OSMPStarter/osmprun.c -o $BASEDIR/osmp
gcc $BASEDIR/Lib/Echoall/echoall.c -o $BASEDIR/Lib/Echoall/echoall