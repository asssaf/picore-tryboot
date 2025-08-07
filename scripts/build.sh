docker build --output type=tar,dest=tryboot.tar --build-arg ARCH=${ARCH} -t builder -f docker/Dockerfile .
