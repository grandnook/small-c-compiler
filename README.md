# Compiler
自作コンパイラ

# Requirements
IntelやAMDなどのいわゆる普通のPCで動く64ビットのLinux環境

Ubuntuの場合:
```bash
$ sudo apt update
$ sudo apt install -y gcc make git binutils libc6-dev
```

# References
[Rui Ueyama, "低レイヤを知りたい人のためのCコンパイラ作成入門"](https://www.sigbus.info/compilerbook)

# クローンする場所
ホームディレクトリ直下
```
$HOME/small-c-compiler
```

クローンする場所を変更したい場合は，``docker-compose.yml``の``volumes``の部分を適切に変更すれば良い．

# Dockerによる環境構築
```bash
$ bash setup.sh
```

# 環境の削除
```bash
$ bash teardown.sh
```
# コンテナ内に入る
```bash
$ bash run.sh
```

# コンテナから出る
```bash
$ exit
```
または，``Ctrl + D``でもok


# アセンブリの便利なサイト
[Compiler Explorer (通称godbolt)](https://godbolt.org/z/RyNqgE)

# （著者推奨のDockerfile）
https://www.sigbus.info/compilerbook/Dockerfile

```Dockerfile
FROM ubuntu:latest
RUN apt update
RUN DEBIAN_FRONTEND=noninteractive apt install -y gcc make git binutils libc6-dev gdb sudo
RUN adduser --disabled-password --gecos '' user
RUN echo 'user ALL=(root) NOPASSWD:ALL' > /etc/sudoers.d/user
USER user
WORKDIR /home/user
```
