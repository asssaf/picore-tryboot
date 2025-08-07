FROM debian:stable AS build

ARG ARCH

RUN apt-get update \
	&& apt-get install -y build-essential crossbuild-essential-${ARCH} squashfs-tools \
	&& apt-get clean

ENV CC=${ARCH/armhf/arm-linux-gnueabihf-gcc}
ENV CC=${CC/arm64/aarch64-linux-gnu-gcc}

ADD Makefile tryboot.c /
RUN make


FROM scratch AS export

COPY --from=build /tryboot.tcz /
COPY --from=build /tryboot.tcz.list /
COPY --from=build /tryboot.tcz.md5.txt /
