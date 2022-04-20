# Upload Service

## Installation

You must install [libhttpserver](https://github.com/etr/libhttpserver) and [opencv](https://github.com/opencv/opencv)

## Usage

```bash
clang++-11 -Wall -o upload-service -lhttpserver `pkg-config --cflags --libs opencv` -march=native src/App.cpp
```

## TODO

- [ ] Send GRPC to user service
- [ ] Validate input
- [ ] Handle exceptions

## Contributing

Pull requests are welcome. For major changes,
please open an issue first to discuss what you would like to change.

Please make sure to update tests as appropriate.

## License

[MIT](https://choosealicense.com/licenses/mit/)
