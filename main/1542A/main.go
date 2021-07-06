package main

import (
	"bufio"
	. "fmt"
	"io"
	"os"
)

func run(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()
	solve := func() {
		var n int
		Fscan(in, &n)
		a := make([]int, n*2)
		cnt := 0
		for i := range a {
			Fscan(in, &a[i])
			if a[i]%2 == 1 {
				cnt++
			}
		}
		if cnt == n {
			Fprintln(out, "Yes")
		} else {
			Fprintln(out, "No")
		}
	}
	var T int
	Fscan(in, &T)
	for i := 0; i < T; i++ {
		solve()
	}
}

func main() {
	run(os.Stdin, os.Stdout)
}
