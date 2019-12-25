package main

func main() {
	var a int
	var f float32 = 11.
	a = 10
	f = 12.0
	var i, j, k int = 3, 4, 5
	var m1 = "st"
	m := 45.3

	const (
		ka = "ka"
		ma = "ma"
		na = "na"
		sa = iota
		ga
		za
		la
	)
	println(a, f, i, j, k, m1, m, ka, ma, na, sa, ga, za, la)
}
