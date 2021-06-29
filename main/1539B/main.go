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
	var n, q int
	var s string
	Fscan(in, &n, &q)
	Fscan(in, &s)
	a := make([]int, n+1)
	for i := 1; i <= n; i++ {
		a[i] = int(s[i-1]-'a') + 1
	}
	for i := 1; i <= n; i++ {
		a[i] += a[i-1]
	}
	for i := 0; i < q; i++ {
		var l, r int
		Fscan(in, &l, &r)
		ans := a[r] - a[l-1]
		Fprintln(out, ans)
	}
}

func main() {
	run(os.Stdin, os.Stdout)
}
