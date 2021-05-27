package main

import "errors"

var (
	zeroDivErr     = errors.New("zero division is not allowed")
	nilErr         = errors.New("nil pointer is not allowed")
	negativeValErr = errors.New("negative value is not allowed")
)
