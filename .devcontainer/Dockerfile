FROM tipibuild/tipi-ubuntu

USER root
RUN apt-get update && export DEBIAN_FRONTEND=noninteractive \
    && apt-get -y install --no-install-recommends \
    gdb \
    python3 \
    python3-pip \
    python3-venv \
    vim

# RUN pip3 install gdbgui

USER tipi