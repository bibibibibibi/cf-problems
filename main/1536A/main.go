package main

import (
	"bufio"
	. "fmt"
	"io"
	"os"
	"sort"
)

func run(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()
	solve := func() {
		var n int
		Fscan(in, &n)
		a := make([]int, n)
		for i := range a {
			Fscan(in, &a[i])
		}
		sort.Ints(a)
		if a[0] < 0 {
			Fprintln(out, "No")
			return
		}
		Fprintln(out, "yes")
		Fprintln(out, a[n-1]+1)
		for i := 0; i <= a[n-1]; i++ {
			Fprint(out, i, " ")
		}
		Fprintln(out)
	}
	var T int
	Fscan(in, &T)
	for Case := 1; Case <= T; Case++ {
		solve()
	}
}

func main() { run(os.Stdin, os.Stdout) }
