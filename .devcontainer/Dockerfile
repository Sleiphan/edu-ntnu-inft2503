FROM alpine:latest AS base

RUN apk --no-cache update
RUN apk --no-cache add g++ gdb make cmake git github-cli

# Add gtk dependencies
RUN apk add --no-cache gtkmm3-dev font-noto