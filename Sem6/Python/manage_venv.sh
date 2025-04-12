#!/bin/bash

VENV_DIR="myenv"

case "$1" in
  create)
    python -m venv $VENV_DIR
    ;;
  activate)
    source $VENV_DIR/Scripts/activate
    ;;
  install)
    $VENV_DIR/bin/pip install -r requirements.txt
    ;;
  deps)
    $VENV_DIR/bin/pip freeze > requirements.txt
    ;;
  clean)
    rm -rf $VENV_DIR
    ;;
  *)
    echo "Использование: $0 {create|activate|install|deps|clean}"
    exit 1
esac
