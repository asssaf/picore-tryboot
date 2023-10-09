docker build -t builder -f docker/Dockerfile .

docker run --rm -it -v $PWD:/mnt -w /mnt -u $(id -u):$(id -g) builder make
