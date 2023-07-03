//go:build ignore

package main

import (
	"fmt"
	"sync"
	//"container/list"
	//"sort"
	//"math/rand"
	//"math"
	//"strings"
)

var once sync.Once

type Lazy struct{}

var lazy *Lazy

func getInstance() *Lazy {
	if lazy == nil {
		once.Do(func() {
			lazy = new(Lazy)
		})
	}
	return lazy
}
func (l *Lazy) dosome() {
	fmt.Println("fgsdfgsd")
}

func main() {
	res := getInstance()
	res.dosome()
}
