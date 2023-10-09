FROM --platform=linux/arm/v5 debian:stable

# a static-user qemu binary that allows running the container on x86
# (the binary is not included in this git repository, build or download your own)
COPY qemu-arm /usr/bin

RUN apt-get update \
	&& apt-get install -y build-essential squashfs-tools \
	&& apt-get clean
