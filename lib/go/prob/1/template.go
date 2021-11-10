package main

import (
	"bufio"
	"errors"
	"fmt"
	"os"
	"strings"
)

var (
	sc             = bufio.NewScanner(os.Stdin)
	ScanErr        = errors.New("failed Scan")
	zeroDivErr     = errors.New("zero devision")
	nilErr         = errors.New("nil error")
	negativeValErr = errors.New("negativa value error")
)

// CLI manages given data
type CLI struct {
	s string
}

// NewCLI generates a pointer to CLI struct
func NewCLI() *CLI {
	return &CLI{}
}

// Scan scans given data and assgin cli field
// validation is also done in this function
func (c *CLI) Scan() error {
	sc.Split(bufio.ScanWords)

	if _, err := fmt.Scanf("%s", &c.s); err != nil {
		return err
	}
	return nil
}

// Solve solves given problem
func (c *CLI) Solve() error {
	var isImg bool = strings.Contains(c.s, "img")
	var isDoc bool = strings.Contains(c.s, "doc")

	if isImg && isDoc {
		fmt.Println("presentation")
	} else if isImg {
		fmt.Println("image")
	} else if isDoc {
		fmt.Println("document")
	} else {
		fmt.Println("other")
	}

	return nil
}
