#!/bin/bash

# Path to models.
BASE_PATH=$(pwd)
MODEL_PATH=$(pwd)/models

# Check if GAZEBO_RESOURCE_PATH already has BASE_PATH.
case "${GAZEBO_RESOURCE_PATH:=$BASE_PATH}" in
    *:$BASE_PATH:*)
        ;;
    *)
        export GAZEBO_RESOURCE_PATH="$BASE_PATH:$GAZEBO_RESOURCE_PATH"
        export GAZEBO_MODEL_PATH="$MODEL_PATH:$GAZEBO_MODEL_PATH"
        ;;
esac

gazebo worlds/icy.world --verbose