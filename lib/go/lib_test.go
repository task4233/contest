package main

import (
	"errors"
	"testing"
)

func TestMod(t *testing.T) {
	tests := []struct {
		name    string
		val     int
		m       int
		want    int
		wantErr error
	}{
		{
			name:    "small mod",
			val:     5,
			m:       3,
			want:    2,
			wantErr: nil,
		},
		{
			name:    "big mod",
			val:     100001010101010101,
			m:       3999393993,
			want:    2724278381,
			wantErr: nil,
		},
		{
			name:    "negative mod",
			val:     -1,
			m:       10,
			want:    9,
			wantErr: nil,
		},
		{
			name:    "zero division",
			val:     31289,
			m:       0,
			want:    -1,
			wantErr: zeroDivErr,
		},
	}

	for _, tt := range tests {
		tt := tt

		t.Run(tt.name, func(t *testing.T) {
			t.Parallel()

			got, err := mod(tt.val, tt.m)
			if err != nil {
				if tt.wantErr != nil {
					if !errors.Is(err, tt.wantErr) {
						t.Errorf("failed with error : %s", err.Error())
					}
				}
			} else if got != tt.want {
				t.Errorf("failed mod(): want: %d, got: %d\n", tt.want, got)
			}
		})
	}
}

func TestChmin(t *testing.T) {
	tests := []struct {
		name    string
		a       int
		b       int
		wantA   int
		wantErr error
	}{
		{
			name:    "2 5",
			a:       2,
			b:       5,
			wantA:   2,
			wantErr: nil,
		},
		{
			name:    "6 3",
			a:       6,
			b:       3,
			wantA:   3,
			wantErr: nil,
		},
		{
			name:    "4 4",
			a:       4,
			b:       4,
			wantA:   4,
			wantErr: nil,
		},
		{
			name:    "-1 as nil 4",
			a:       -1,
			b:       4,
			wantA:   -1,
			wantErr: nilErr,
		},
	}

	for _, tt := range tests {
		tt := tt

		t.Run(tt.name, func(t *testing.T) {
			t.Parallel()

			var err error

			// it treats -1 as nil
			if tt.a == -1 {
				_, err = chmin(nil, tt.b)
			} else {
				_, err = chmin(&tt.a, tt.b)
			}

			if err != nil {
				if tt.wantErr != nil {
					if !errors.Is(err, tt.wantErr) {
						t.Errorf("failed with error : %s", err.Error())
					}
				}
			} else if tt.a != tt.wantA {
				t.Errorf("failed mod(): want: %d, got: %d\n", tt.wantA, tt.a)
			}
		})
	}
}

func TestChmax(t *testing.T) {
	tests := []struct {
		name    string
		a       int
		b       int
		wantA   int
		wantErr error
	}{
		{
			name:    "2 5",
			a:       2,
			b:       5,
			wantA:   5,
			wantErr: nil,
		},
		{
			name:    "6 3",
			a:       6,
			b:       3,
			wantA:   6,
			wantErr: nil,
		},
		{
			name:    "4 4",
			a:       4,
			b:       4,
			wantA:   4,
			wantErr: nil,
		},
		{
			name:    "-1 as nil 4",
			a:       -1,
			b:       4,
			wantA:   -1,
			wantErr: nilErr,
		},
	}

	for _, tt := range tests {
		tt := tt

		t.Run(tt.name, func(t *testing.T) {
			t.Parallel()

			var err error

			// it treats -1 as nil
			if tt.a == -1 {
				_, err = chmax(nil, tt.b)
			} else {
				_, err = chmax(&tt.a, tt.b)
			}

			if err != nil {
				if tt.wantErr != nil {
					if !errors.Is(err, tt.wantErr) {
						t.Errorf("failed with error : %s", err.Error())
					}
				}
			} else if tt.a != tt.wantA {
				t.Errorf("failed mod(): want: %d, got: %d\n", tt.wantA, tt.a)
			}
		})
	}
}

func TestSum(t *testing.T) {
	tests := []struct {
		name string
		vals []int
		want int
	}{
		{
			name: "single value",
			vals: []int{1},
			want: 1,
		},
		{
			name: "multiple value",
			vals: []int{1, 3, 5, 7, 9},
			want: 25,
		},
	}

	for _, tt := range tests {
		tt := tt

		t.Run(tt.name, func(t *testing.T) {
			t.Parallel()

			got := sum(tt.vals...)
			if got != tt.want {
				t.Errorf("failed mod(): want: %d, got: %d\n", tt.want, got)
			}
		})
	}
}

func TestAbs(t *testing.T) {
	tests := []struct {
		name string
		val  int
		want int
	}{
		{
			name: "positive value",
			val:  1,
			want: 1,
		},
		{
			name: "negative value",
			val:  -25,
			want: 25,
		},
		{
			name: "zero value",
			val:  0,
			want: 0,
		},
	}

	for _, tt := range tests {
		tt := tt

		t.Run(tt.name, func(t *testing.T) {
			t.Parallel()

			got := abs(tt.val)
			if got != tt.want {
				t.Errorf("failed mod(): want: %d, got: %d\n", tt.want, got)
			}
		})
	}
}

func TestPow(t *testing.T) {
	tests := []struct {
		name    string
		a       int
		e       int
		want    int
		wantErr error
	}{
		{
			name:    "3^4",
			a:       3,
			e:       4,
			want:    81,
			wantErr: nil,
		}, {
			name:    "-1^3",
			a:       -1,
			e:       3,
			want:    -1,
			wantErr: negativeValErr,
		}, {
			name:    "1^0",
			a:       1,
			e:       0,
			want:    1,
			wantErr: nil,
		}, {
			name:    "0^1",
			a:       0,
			e:       1,
			want:    0,
			wantErr: nil,
		}, {
			name:    "0^0",
			a:       0,
			e:       0,
			want:    1,
			wantErr: nil,
		},
	}

	for _, tt := range tests {
		tt := tt

		t.Run(tt.name, func(t *testing.T) {
			t.Parallel()

			got, err := pow(tt.a, tt.e)
			if err != nil {
				if tt.wantErr != nil {
					if !errors.Is(err, tt.wantErr) {
						t.Errorf("failed with error : %s", err.Error())
					}
				}
			} else if got != tt.want {
				t.Errorf("failed pow(): want: %d, got: %d\n", tt.want, tt.a)
			}
		})
	}
}
