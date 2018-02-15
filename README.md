# KymoKnot - A software package and webserver to identify and locate knots

KymoKnot provides programs and libraries to localize the knotted portion of knotted rings and linear chains. The Minimally-Interfering closure [1] is used to circularize both linear chains and chain subportions. An interactive web-server interface is available at [](http://dl413f.usc.edu/kntloc/interactive.php).

The package currently provides 3 programs.

* `KymoKnot_ring.x`
* `KymoKnot_linear.x`
* `K_close.x`


The first two programs locate knots, respectively on ring and linear chains, using the simplification only as a mean to reduce the number of chain subportions to be considered in the search for the knotted portion. The topology of each chain subportion is evaluated by closing the corresponding portion of the original, unsimplified chain.  `K_close.x` takes an open chain in input and closes it using the Minimally-Interfering closure scheme.

When searching for knotted portions, different search schemes identify different entanglement properties of a chain and may in general give different results.  For a detailed study, see ref [2].  In the current version, the bottom-up, top-down and  'unsafe' bottom-up search schemes can be used. The first two are enabled by default if no search scheme is specified by the user.

**Important.** KymoKnot identifies knots based on the Alexander determinants in $t=-1$ and $t=-2$ [1]. Prime knots with 8 or more crossings can have the same Alexander determinants of other knots, including composite one; therefore the
code must be used with caution when analyzing complex knots.  The table of known knots is in the header file `KNT_table.h`.

[1]: 1. Tubiana L., Orlandini E, Micheletti C
[Probing the Entanglement and Locating Knots in Ring Polymers: A Comparative Study of Different Arc Closure Schemes](http://ptp.ipap.jp/link?PTPS/191/192) Progress of Theoretical Physics supplement, 192, 192-204 (2011)


[2]: 2. Tubiana L., Orlandini E, Micheletti C
[Multiscale entanglement in ring polymers under spherical confinement](http://prl.aps.org/pdf/PRL/v107/i18/e188302)
Phys. Rev. Lett. 107, pg 188302 (2011).


## 15-02-2018 

KymoKnot is a direct evolution of [LocKnot](https://bitbucket.org/locknot/locknot)

## Installation
From the base directory, run `make`. This will compile also the local version of qhull needed by the Minimally-Interfering closure algorithm.

## Usage
usage: `KymoKnot_ring.x [options] input_file` (the same holds for KymoKnot_linear.x).

input file must be in the format:

        N
        x y z
        x y z
        ...
where N is the length of the coordinate sets.  If the input files contain coordinate of rings, the edges `x_0 y_0 z_0` and `x_(N-1) y_(N-1) z_(N-1)` must coincide.  Several configurations can be given one after the other in the same input file

### OUTPUT
- BU__  [ -b option ]: shortest knotted portion. Bottom-up search
- NBU__ [ -u option ]:  bottom-up search, without unknottedness check on complementar arc
- TD__  [ -t option ]: shortest continuosly knotted portion. Top-down search

### OUTPUT FILE FORMAT:
 `RING i Adet_1 Adet_2 start end Length` where `i` is the index of the ring, `Adet_1` and `Adet_2` are the Alexander determinants start end and length are the starting point, ending point and length of the knotted portion.  In `KymoKnot_ring.x` and `KymoKnot_linear.x`, when sevearl knotted portions are found they are printed on the same line.

-------------------------------------------------------
## OPTIONS:
* -h:              print this help and exit.
* -s <max_stride>:         maximum stride for rectification. Default is none. Negative values in input set the stride to unlimited
* -m <mem_size>:   USE WITH CAUTION! Set the size of memory manually. Insert the expected length of the chain after simplification.
* -r <seed>:       set the pseudo random number generator's seed. Default: use time()+getpid().
* -b:      		Perform bottom-up search. ( DEFAULT )
* -t:      		Perform top-down search.  ( DEFAULT )
* -u:      		Perform bottom-up search without checking the complementar arc.
* -F <start>: (use only in conjunction with -T) perform knot search between <start> and <end>, included.
* -T <end>: 	(use only in conjunction with -F) perform knot search between <start> and <end>, included.
