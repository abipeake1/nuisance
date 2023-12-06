#!/usr/bin/env bash
#script to generate events for MicroBoone with tune...
echo "Tune chosen is $1"
NUIS_QUIET=ON nuis-gen GENIE -t Ar -E MicroBooNE -p 14 -n 100000 \
    --output-file $1"_microbooneevents.root" \
    --event-generator-list Default