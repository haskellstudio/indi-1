/*
 *   libDSPAU - a digital signal processing library for astronomy usage
 *   Copyright (C) 2017  Ilia Platone <info@iliaplatone.com>
 *
 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include "libdspau.h"

double dspau_minmidmax(double* in, int len, double *min, double *max)
{
	int i;
	double mn = DBL_MAX;
	double mx = DBL_MIN;
	for(i = 0; i < len; i++) {
		mn = (in[i] < mn ? in[i] : mn);
		mx = (in[i] > mx ? in[i] : mx);
	}
	*min = mn;
	*max = mx;
	return (double)((mx - mn) / 2.0 + mn);
}

double dspau_mean(double* in, int len)
{
	int i;
	double mean = 0.0;
	double l = (double)len;
	for(i = 0; i < len; i++) {
		mean += in[i];
	}
	mean /=  l;
	return mean;
}

