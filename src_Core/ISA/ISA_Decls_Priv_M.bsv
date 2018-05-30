// Copyright (c) 2013-2018 Bluespec, Inc. All Rights Reserved

// ================================================================
// This is an 'include' file, not a separate BSV package
//
// Contains RISC-V Machine-Level ISA defs
//
// ================================================================

// ================================================================
// Machine-level CSRs

CSR_Addr   csr_mvendorid      = 12'hF11;    // Vendor ID
CSR_Addr   csr_marchid        = 12'hF12;    // Architecture ID
CSR_Addr   csr_mimpid         = 12'hF13;    // Implementation ID
CSR_Addr   csr_mhartid        = 12'hF14;    // Hardware thread ID

CSR_Addr   csr_mstatus        = 12'h300;    // Machine status
CSR_Addr   csr_misa           = 12'h301;    // ISA and extensions
CSR_Addr   csr_medeleg        = 12'h302;    // Machine exception delegation
CSR_Addr   csr_mideleg        = 12'h303;    // Machine interrupt delegation
CSR_Addr   csr_mie            = 12'h304;    // Machine interrupt-enable
CSR_Addr   csr_mtvec          = 12'h305;    // Machine trap handler base address
CSR_Addr   csr_mcounteren     = 12'h306;    // Machine counter enable

CSR_Addr   csr_mscratch       = 12'h340;    // Scratch reg for machine trap handlers
CSR_Addr   csr_mepc           = 12'h341;    // Machine exception program counter
CSR_Addr   csr_mcause         = 12'h342;    // Machine trap cause
CSR_Addr   csr_mtval          = 12'h343;    // Machine bad address
CSR_Addr   csr_mip            = 12'h344;    // Machine interrupt pending

CSR_Addr   csr_pmpcfg0        = 12'h3A0;    // PMP Config
CSR_Addr   csr_pmpcfg1        = 12'h3A1;    // PMP Config
CSR_Addr   csr_pmpcfg2        = 12'h3A2;    // PMP Config
CSR_Addr   csr_pmpcfg3        = 12'h3A3;    // PMP Config
CSR_Addr   csr_pmpaddr0       = 12'h3B0;    // PMP address register
CSR_Addr   csr_pmpaddr1       = 12'h3B1;    // PMP address register
CSR_Addr   csr_pmpaddr2       = 12'h3B2;    // PMP address register
CSR_Addr   csr_pmpaddr3       = 12'h3B3;    // PMP address register
CSR_Addr   csr_pmpaddr4       = 12'h3B4;    // PMP address register
CSR_Addr   csr_pmpaddr5       = 12'h3B5;    // PMP address register
CSR_Addr   csr_pmpaddr6       = 12'h3B6;    // PMP address register
CSR_Addr   csr_pmpaddr7       = 12'h3B7;    // PMP address register
CSR_Addr   csr_pmpaddr8       = 12'h3B8;    // PMP address register
CSR_Addr   csr_pmpaddr9       = 12'h3B9;    // PMP address register
CSR_Addr   csr_pmpaddr10      = 12'h3BA;    // PMP address register
CSR_Addr   csr_pmpaddr11      = 12'h3BB;    // PMP address register
CSR_Addr   csr_pmpaddr12      = 12'h3BC;    // PMP address register
CSR_Addr   csr_pmpaddr13      = 12'h3BD;    // PMP address register
CSR_Addr   csr_pmpaddr14      = 12'h3BE;    // PMP address register
CSR_Addr   csr_pmpaddr15      = 12'h3BF;    // PMP address register

CSR_Addr   csr_mcycle         = 12'hB00;    // Machine cycle counter
CSR_Addr   csr_minstret       = 12'hB02;    // Machine Instructions retired counter

CSR_Addr   csr_mhpmcounter3   = 12'hB03;    // Machine performance-monitoring counter
CSR_Addr   csr_mhpmcounter4   = 12'hB04;    // Machine performance-monitoring counter
CSR_Addr   csr_mhpmcounter5   = 12'hB05;    // Machine performance-monitoring counter
CSR_Addr   csr_mhpmcounter6   = 12'hB06;    // Machine performance-monitoring counter
CSR_Addr   csr_mhpmcounter7   = 12'hB07;    // Machine performance-monitoring counter
CSR_Addr   csr_mhpmcounter8   = 12'hB08;    // Machine performance-monitoring counter
CSR_Addr   csr_mhpmcounter9   = 12'hB09;    // Machine performance-monitoring counter
CSR_Addr   csr_mhpmcounter10  = 12'hB0A;    // Machine performance-monitoring counter
CSR_Addr   csr_mhpmcounter11  = 12'hB0B;    // Machine performance-monitoring counter
CSR_Addr   csr_mhpmcounter12  = 12'hB0C;    // Machine performance-monitoring counter
CSR_Addr   csr_mhpmcounter13  = 12'hB0D;    // Machine performance-monitoring counter
CSR_Addr   csr_mhpmcounter14  = 12'hB0E;    // Machine performance-monitoring counter
CSR_Addr   csr_mhpmcounter15  = 12'hB0F;    // Machine performance-monitoring counter
CSR_Addr   csr_mhpmcounter16  = 12'hB10;    // Machine performance-monitoring counter
CSR_Addr   csr_mhpmcounter17  = 12'hB11;    // Machine performance-monitoring counter
CSR_Addr   csr_mhpmcounter18  = 12'hB12;    // Machine performance-monitoring counter
CSR_Addr   csr_mhpmcounter19  = 12'hB13;    // Machine performance-monitoring counter
CSR_Addr   csr_mhpmcounter20  = 12'hB14;    // Machine performance-monitoring counter
CSR_Addr   csr_mhpmcounter21  = 12'hB15;    // Machine performance-monitoring counter
CSR_Addr   csr_mhpmcounter22  = 12'hB16;    // Machine performance-monitoring counter
CSR_Addr   csr_mhpmcounter23  = 12'hB17;    // Machine performance-monitoring counter
CSR_Addr   csr_mhpmcounter24  = 12'hB18;    // Machine performance-monitoring counter
CSR_Addr   csr_mhpmcounter25  = 12'hB19;    // Machine performance-monitoring counter
CSR_Addr   csr_mhpmcounter26  = 12'hB1A;    // Machine performance-monitoring counter
CSR_Addr   csr_mhpmcounter27  = 12'hB1B;    // Machine performance-monitoring counter
CSR_Addr   csr_mhpmcounter28  = 12'hB1C;    // Machine performance-monitoring counter
CSR_Addr   csr_mhpmcounter29  = 12'hB1D;    // Machine performance-monitoring counter
CSR_Addr   csr_mhpmcounter30  = 12'hB1E;    // Machine performance-monitoring counter
CSR_Addr   csr_mhpmcounter31  = 12'hB1F;    // Machine performance-monitoring counter

CSR_Addr   csr_mcycleh        = 12'hB80;    // Upper 32 bits of csr_mcycle (RV32I only)
CSR_Addr   csr_minstreth      = 12'hB82;    // Upper 32 bits of csr_minstret (RV32I only)

CSR_Addr   csr_mhpmcounter3h  = 12'hB83;    // Upper 32 bits of machine performance-monitoring counter
CSR_Addr   csr_mhpmcounter4h  = 12'hB84;    // Upper 32 bits of machine performance-monitoring counter
CSR_Addr   csr_mhpmcounter5h  = 12'hB85;    // Upper 32 bits of machine performance-monitoring counter
CSR_Addr   csr_mhpmcounter6h  = 12'hB86;    // Upper 32 bits of machine performance-monitoring counter
CSR_Addr   csr_mhpmcounter7h  = 12'hB87;    // Upper 32 bits of machine performance-monitoring counter
CSR_Addr   csr_mhpmcounter8h  = 12'hB88;    // Upper 32 bits of machine performance-monitoring counter
CSR_Addr   csr_mhpmcounter9h  = 12'hB89;    // Upper 32 bits of machine performance-monitoring counter
CSR_Addr   csr_mhpmcounter10h = 12'hB8A;    // Upper 32 bits of machine performance-monitoring counter
CSR_Addr   csr_mhpmcounter11h = 12'hB8B;    // Upper 32 bits of machine performance-monitoring counter
CSR_Addr   csr_mhpmcounter12h = 12'hB8C;    // Upper 32 bits of machine performance-monitoring counter
CSR_Addr   csr_mhpmcounter13h = 12'hB8D;    // Upper 32 bits of machine performance-monitoring counter
CSR_Addr   csr_mhpmcounter14h = 12'hB8E;    // Upper 32 bits of machine performance-monitoring counter
CSR_Addr   csr_mhpmcounter15h = 12'hB8F;    // Upper 32 bits of machine performance-monitoring counter
CSR_Addr   csr_mhpmcounter16h = 12'hB90;    // Upper 32 bits of machine performance-monitoring counter
CSR_Addr   csr_mhpmcounter17h = 12'hB91;    // Upper 32 bits of machine performance-monitoring counter
CSR_Addr   csr_mhpmcounter18h = 12'hB92;    // Upper 32 bits of machine performance-monitoring counter
CSR_Addr   csr_mhpmcounter19h = 12'hB93;    // Upper 32 bits of machine performance-monitoring counter
CSR_Addr   csr_mhpmcounter20h = 12'hB94;    // Upper 32 bits of machine performance-monitoring counter
CSR_Addr   csr_mhpmcounter21h = 12'hB95;    // Upper 32 bits of machine performance-monitoring counter
CSR_Addr   csr_mhpmcounter22h = 12'hB96;    // Upper 32 bits of machine performance-monitoring counter
CSR_Addr   csr_mhpmcounter23h = 12'hB97;    // Upper 32 bits of machine performance-monitoring counter
CSR_Addr   csr_mhpmcounter24h = 12'hB98;    // Upper 32 bits of machine performance-monitoring counter
CSR_Addr   csr_mhpmcounter25h = 12'hB99;    // Upper 32 bits of machine performance-monitoring counter
CSR_Addr   csr_mhpmcounter26h = 12'hB9A;    // Upper 32 bits of machine performance-monitoring counter
CSR_Addr   csr_mhpmcounter27h = 12'hB9B;    // Upper 32 bits of machine performance-monitoring counter
CSR_Addr   csr_mhpmcounter28h = 12'hB9C;    // Upper 32 bits of machine performance-monitoring counter
CSR_Addr   csr_mhpmcounter29h = 12'hB9D;    // Upper 32 bits of machine performance-monitoring counter
CSR_Addr   csr_mhpmcounter30h = 12'hB9E;    // Upper 32 bits of machine performance-monitoring counter
CSR_Addr   csr_mhpmcounter31h = 12'hB9F;    // Upper 32 bits of machine performance-monitoring counter

CSR_Addr   csr_mhpmevent3     = 12'h323;    // Machine performance-monitoring event selector
CSR_Addr   csr_mhpmevent4     = 12'h324;    // Machine performance-monitoring event selector
CSR_Addr   csr_mhpmevent5     = 12'h325;    // Machine performance-monitoring event selector
CSR_Addr   csr_mhpmevent6     = 12'h326;    // Machine performance-monitoring event selector
CSR_Addr   csr_mhpmevent7     = 12'h327;    // Machine performance-monitoring event selector
CSR_Addr   csr_mhpmevent8     = 12'h328;    // Machine performance-monitoring event selector
CSR_Addr   csr_mhpmevent9     = 12'h329;    // Machine performance-monitoring event selector
CSR_Addr   csr_mhpmevent10    = 12'h32A;    // Machine performance-monitoring event selector
CSR_Addr   csr_mhpmevent11    = 12'h32B;    // Machine performance-monitoring event selector
CSR_Addr   csr_mhpmevent12    = 12'h32C;    // Machine performance-monitoring event selector
CSR_Addr   csr_mhpmevent13    = 12'h32D;    // Machine performance-monitoring event selector
CSR_Addr   csr_mhpmevent14    = 12'h32E;    // Machine performance-monitoring event selector
CSR_Addr   csr_mhpmevent15    = 12'h32F;    // Machine performance-monitoring event selector
CSR_Addr   csr_mhpmevent16    = 12'h330;    // Machine performance-monitoring event selector
CSR_Addr   csr_mhpmevent17    = 12'h331;    // Machine performance-monitoring event selector
CSR_Addr   csr_mhpmevent18    = 12'h332;    // Machine performance-monitoring event selector
CSR_Addr   csr_mhpmevent19    = 12'h333;    // Machine performance-monitoring event selector
CSR_Addr   csr_mhpmevent20    = 12'h334;    // Machine performance-monitoring event selector
CSR_Addr   csr_mhpmevent21    = 12'h335;    // Machine performance-monitoring event selector
CSR_Addr   csr_mhpmevent22    = 12'h336;    // Machine performance-monitoring event selector
CSR_Addr   csr_mhpmevent23    = 12'h337;    // Machine performance-monitoring event selector
CSR_Addr   csr_mhpmevent24    = 12'h338;    // Machine performance-monitoring event selector
CSR_Addr   csr_mhpmevent25    = 12'h339;    // Machine performance-monitoring event selector
CSR_Addr   csr_mhpmevent26    = 12'h33A;    // Machine performance-monitoring event selector
CSR_Addr   csr_mhpmevent27    = 12'h33B;    // Machine performance-monitoring event selector
CSR_Addr   csr_mhpmevent28    = 12'h33C;    // Machine performance-monitoring event selector
CSR_Addr   csr_mhpmevent29    = 12'h33D;    // Machine performance-monitoring event selector
CSR_Addr   csr_mhpmevent30    = 12'h33E;    // Machine performance-monitoring event selector
CSR_Addr   csr_mhpmevent31    = 12'h33F;    // Machine performance-monitoring event selector

CSR_Addr   csr_tselect        = 12'h7A0;    // Debug/Trace trigger register select
CSR_Addr   csr_tdata1         = 12'h7A1;    // First Debug/Trace trigger data
CSR_Addr   csr_tdata2         = 12'h7A2;    // Secont Debug/Trace trigger data
CSR_Addr   csr_tdata3         = 12'h7A3;    // Third Debug/Trace trigger data

CSR_Addr   csr_addr_dcsr      = 12'h7B0;    // Debug control and status
CSR_Addr   csr_addr_dpc       = 12'h7B1;    // Debug PC
CSR_Addr   csr_addr_dscratch0 = 12'h7B2;    // Debug scratch0
CSR_Addr   csr_addr_dscratch1 = 12'h7B3;    // Debug scratch1

CSR_Addr   csr_addr_watch_n     = 12'hBC0;    // When a watchpoint is hit, this reg holds the watchpoint number that was hit (1..)
CSR_Addr   csr_addr_watchpoint1 = 12'hBC1;    // Watchpoint 1 (contains an address being watched)

// ================================================================
// Logical view of csr_misa register

typedef struct {
   Bit #(2) mxl;
   Bit #(1) z;  Bit #(1) y;
   Bit #(1) x;  Bit #(1) w;  Bit #(1) v;  Bit #(1) u;  Bit #(1) t;  Bit #(1) s;  Bit #(1) r;  Bit #(1) q;
   Bit #(1) p;  Bit #(1) o;  Bit #(1) n;  Bit #(1) m;  Bit #(1) l;  Bit #(1) k;  Bit #(1) j;  Bit #(1) i;
   Bit #(1) h;  Bit #(1) g;  Bit #(1) f;  Bit #(1) e;  Bit #(1) d;  Bit #(1) c;  Bit #(1) b;  Bit #(1) a;
   } MISA
deriving (Bits);

Bit #(2) misa_mxl_default  = 0;
Bit #(2) misa_mxl_32       = 1;
Bit #(2) misa_mxl_64       = 2;
Bit #(2) misa_mxl_128      = 3;

function WordXL misa_to_word (MISA ms);
   return {ms.mxl,
	   0,        // expands appropriately for RV32 and RV64
	   ms.z, ms.y,
	   ms.x, ms.w, ms.v, ms.u, ms.t, ms.s, ms.r, ms.q,
	   ms.p, ms.o, ms.n, ms.m, ms.l, ms.k, ms.j, ms.i,
	   ms.h, ms.g, ms.f, ms.e, ms.d, ms.c, ms.b, ms.a};
endfunction

function MISA word_to_misa (WordXL x);
   return MISA {mxl: x [xlen-1:xlen-2],
		z: x [25], y: x [24],
		x: x [23], w: x [22], v: x [21], u: x [20], t: x [19], s: x [18], r: x [17], q: x [16],
		p: x [15], o: x [14], n: x [13], m: x [12], l: x [11], k: x [10], j: x  [9], i: x  [8],
		h: x  [7], g: x  [6], f: x  [5], e: x  [4], d: x  [3], c: x  [2], b: x  [1], a: x  [0]};
endfunction

instance FShow #(MISA);
   function Fmt fshow (MISA misa);
      let fmt_mxl = case (misa.mxl)
			1: $format ("mxl 32");
			2: $format ("mxl 64");
			3: $format ("mxl 128");
			default: $format ("mxl unknown %0d", misa.mxl);
		     endcase;
      return (  fmt_mxl
	      + $format ((misa.z == 1'b1) ? "Z" : "")
	      + $format ((misa.y == 1'b1) ? "Y" : "")
	      + $format ((misa.x == 1'b1) ? "X" : "")
	      + $format ((misa.w == 1'b1) ? "W" : "")
	      + $format ((misa.v == 1'b1) ? "V" : "")
	      + $format ((misa.u == 1'b1) ? "U" : "")
	      + $format ((misa.t == 1'b1) ? "T" : "")
	      + $format ((misa.s == 1'b1) ? "S" : "")
	      + $format ((misa.r == 1'b1) ? "R" : "")
	      + $format ((misa.q == 1'b1) ? "Q" : "")
	      + $format ((misa.p == 1'b1) ? "P" : "")
	      + $format ((misa.o == 1'b1) ? "O" : "")
	      + $format ((misa.n == 1'b1) ? "N" : "")
	      + $format ((misa.m == 1'b1) ? "M" : "")
	      + $format ((misa.l == 1'b1) ? "L" : "")
	      + $format ((misa.k == 1'b1) ? "K" : "")
	      + $format ((misa.j == 1'b1) ? "J" : "")
	      + $format ((misa.i == 1'b1) ? "I" : "")
	      + $format ((misa.h == 1'b1) ? "H" : "")
	      + $format ((misa.g == 1'b1) ? "G" : "")
	      + $format ((misa.f == 1'b1) ? "F" : "")
	      + $format ((misa.d == 1'b1) ? "E" : "")
	      + $format ((misa.d == 1'b1) ? "D" : "")
	      + $format ((misa.c == 1'b1) ? "C" : "")
	      + $format ((misa.b == 1'b1) ? "B" : "")
	      + $format ((misa.a == 1'b1) ? "A" : ""));
   endfunction
endinstance

// ================================================================
// MSTATUS

// ----------------
// Logical view

typedef struct {
   Bit #(1)   sd;     // Some dirty in XS or FS
`ifdef RV64
   Bit #(2)   sxl;    // XLEN in S Priv
   Bit #(2)   uxl;    // XLEN in U Priv
`endif
   Bit #(1)   tsr;    // Trap SRET
   Bit #(1)   tw;     // Timeout Wait
   Bit #(1)   tvm;    // Trap Virt Mem
   Bit #(1)   mxr;    // Make Executable Readable (0:R only, 1:R or X)
   Bit #(1)   sum;    // Supervisor Memory Access (0: U fault, 1: ok)
   Bit #(1)   mprv;   // Modify Privilege for Load/Store (0:normal, 1:MPP)
   Bit #(2)   xs;     // Extension state for context save/restore
   Bit #(2)   fs;     // Floating point state for context save/restore
   Priv_Mode  mpp;    // Previous privilege level
   Priv_Mode  spp;    // Previous privilege level
   Vector #(Num_Priv_Modes, Bit #(1)) pies;    // Previous interrupt enables
   Vector #(Num_Priv_Modes, Bit #(1)) ies;     // Interrupt enables
   } MStatus
deriving (Bits);

// Valus for FS and XS

Bit #(2) fs_xs_off      = 2'h0;
Bit #(2) fs_xs_initial  = 2'h1;
Bit #(2) fs_xs_clean    = 2'h2;
Bit #(2) fs_xs_dirty    = 2'h3;

instance FShow #(MStatus);
   function Fmt fshow (MStatus ms);
      return (  $format ("MStatus{")
	      + $format ("sd:%0d", ms.sd)
`ifdef RV64
	      + $format (" sxl:'b%b", ms.sxl)
	      + $format (" uxl:'b%b", ms.uxl)
`endif
	      + $format (" tsr:%d",  ms.tsr)
	      + $format (" tw:%d",   ms.tw)
	      + $format (" tvm:%d",  ms.tvm)
	      + $format (" mxr:%d",  ms.mxr)
	      + $format (" sum:%d",  ms.sum)
	      + $format (" mprv:%d", ms.mprv)

	      + $format (" xs:'b%b",   ms.xs)
	      + $format (" fs:'b%b",   ms.fs)

	      + $format (" mpp:'b%b",   ms.mpp)
	      + $format (" spp:'b%b",   ms.spp)

	      + $format (" pies: m %0d s %0d u %0d",
			 ms.pies [m_Priv_Mode], ms.pies [s_Priv_Mode], ms.pies [u_Priv_Mode])

	      + $format (" ies: m %0d s %0d u %0d",
			 ms.ies [m_Priv_Mode], ms.ies [s_Priv_Mode], ms.ies [u_Priv_Mode])
	      );
   endfunction
endinstance

// ----------------
// Reset value of mstatus

function MStatus mstatus_reset_value;
   MStatus mstatus = unpack (0);

`ifdef RV64
`ifdef ISA_PRIV_S
   mstatus.sxl = 2;
`endif
`ifdef ISA_PRIV_U
   mstatus.uxl = 2;
`endif
`endif

   mstatus.mpp = u_Priv_Mode;

   // Disable all interrupts
   mstatus.ies [m_Priv_Mode] = 0;
   mstatus.ies [s_Priv_Mode] = 0;
   mstatus.ies [u_Priv_Mode] = 0;
   return mstatus;
endfunction

// ----------------
// Conversion from logical view of mstatus to/from bit-representation

function WordXL mstatus_to_word (MStatus ms);
   return {ms.sd,
`ifdef RV64
	   0,        // WPRI field, expands appropriately for RV64
	   ms.sxl,
	   ms.uxl,
	   9'b0,     // WPRI field
`else
	   0,        // WPRI field, expands appropriately for RV32
`endif
	   ms.tsr,
	   ms.tw,
	   ms.tvm,
	   ms.mxr,
	   ms.sum,
	   ms.mprv,
	   ms.xs,
	   ms.fs,
	   pack (ms.mpp),
	   2'b0,                 // WPRI field
	   pack (ms.spp) [0],

	   ms.pies [m_Priv_Mode],
	   ms.pies [reserved_Priv_Mode],
	   ms.pies [s_Priv_Mode],
	   ms.pies [u_Priv_Mode],

	   ms.ies [m_Priv_Mode],
	   ms.ies [reserved_Priv_Mode],
	   ms.ies [s_Priv_Mode],
	   ms.ies [u_Priv_Mode]
	   };
endfunction

// TODO: this should take current privilege mode and misa into account (see Cissr code, e.g.)
function MStatus word_to_mstatus (WordXL x);
   return MStatus {sd: msb (x),
`ifdef RV64
`ifdef ISA_PRIV_S
                   sxl: 2'b10,                   // sxl: x [35:34],
`else
                   sxl: 0,
`endif
`ifdef ISA_PRIV_U
                   uxl: 2'b10,                   // uxl: x [33:32],
`else
                   uxl: 0,
`endif
`endif
		   tsr:  x [22],
		   tw:  x [21],
		   tvm:  x [20],
		   mxr:  x [19],
		   sum:  x [18],
		   mprv: x [17],
		   xs:   x [16:15],
`ifdef ISA_FD
		   fs:   x [14:13],
`else
		   fs:   0,
`endif
		   mpp: x [12:11],
		   spp: (x[8] == 0) ? u_Priv_Mode : s_Priv_Mode,
		   pies: unpack ({ x[7], 1'b0, x[5], x[4] }),
		   ies:  unpack ({ x[3], 1'b0, x[1], x[0] })
		};
endfunction

// ----------------
// Restricted view of MSTATUS as SSTATUS

function WordXL fn_read_sstatus (MStatus x);
   WordXL mstatus_w = mstatus_to_word (x);
`ifdef RV32
   WordXL sstatus_w = {mstatus_w [31],        // SD
		       11'h0,
		       mstatus_w [19:18],     // MXR, SUM
		       1'h0,
		       mstatus_w [16:13],     // XS,FS
		       4'h0,
		       mstatus_w [8],         // SPP
		       2'h0,
		       mstatus_w [5:4],       // SPIE, UPIE
		       2'h0,
		       mstatus_w [1:0]};      // SIE, UIE
`endif

`ifdef RV64
   WordXL sstatus_w = {mstatus_w [63],        // SD
		       29'h0,
		       mstatus_w [33:32],     // UXL
		       12'h0,
		       mstatus_w [19:18],     // MXR, SUM
		       1'h0,
		       mstatus_w [16:13],     // XS,FS
		       4'h0,
		       mstatus_w [8],         // SPP
		       2'h0,
		       mstatus_w [5:4],       // SPIE, UPIE
		       2'h0,
		       mstatus_w [1:0]};      // SIE, UIE
`endif

   return sstatus_w;
endfunction

function MStatus fn_write_sstatus (MStatus mstatus, WordXL x);
  MStatus res = mstatus;
  MStatus mx = word_to_mstatus (x);
  // Update the fields which are not WPRI
  res.sd   = mx.sd;
`ifdef RV64
  res.uxl  = mx.uxl;
`endif
  res.mxr  = mx.mxr;
  res.sum  = mx.sum;
  res.xs   = mx.xs;
  res.fs   = mx.fs;
  res.spp  = mx.spp;
  res.pies[1] = mx.pies[1];
  res.pies[0] = mx.pies[0];
  res.ies[1]  = mx.ies[1];
  res.ies[0]  = mx.ies[0];
  return res;
endfunction

// ----------------
// Help functions to manipulate mstatus on traps and trap-returns

function Priv_Mode fn_new_priv_on_exception (Priv_Mode  from_priv,
					     Bool       interrupt,
					     Exc_Code   exc_code,
					     Bit #(16)  medeleg,
					     Bit #(12)  mideleg,
					     Bit #(16)  sedeleg,
					     Bit #(12)  sideleg);
   // TODO: Make misa an argument
   MISA misa; misa.s = 1'b0; misa.u = 1'b0; misa.n = 1'b0;
`ifdef ISA_PRIV_S
   misa.s = 1'b1;
`endif
`ifdef ISA_PRIV_U
   misa.u = 1'b1;
`endif
`ifdef ISA_N
   misa.n = 1'b1;
`endif

   Priv_Mode to_priv = m_Priv_Mode;
   Bit #(1) deleg_bit = 1'b0;

   // If the current priv mode is M, it cannot be delegated.
   if (from_priv < m_Priv_Mode) begin
      // If S is supported
      if (misa.s == 1'b1) begin
	 // Look in medeleg/mideleg for the cause bit; if set, delegate.
	 if (interrupt)
	    deleg_bit = mideleg [exc_code];
	 else
	    deleg_bit = medeleg [exc_code];
	 if (deleg_bit == 1'b1) begin
	    // If the current priv mode is S, then delegate to S.
	    to_priv = s_Priv_Mode;
	    // If the current priv mode is U, and user mode traps are supported,
	    // then consult sedeleg/sideleg to determine if delegated to U mode.
	    if ((from_priv == u_Priv_Mode) && (misa.n == 1'b1)) begin
	       if (interrupt)
		  deleg_bit = sideleg [exc_code];
	       else
		  deleg_bit = sedeleg [exc_code];
	       if (deleg_bit == 1'b1)
	          to_priv = u_Priv_Mode;
	    end
	 end
      end
      else begin
	 // S is not supported
	 // If user mode traps are supported,
	 // then consult medele/mideleg to determine if delegated to U mode.
	 if (misa.n == 1'b1) begin
	    // Look in medeleg/mideleg for the cause bit; if set, delegate.
	    if (interrupt)
	       deleg_bit = mideleg [exc_code];
	    else
	       deleg_bit = medeleg [exc_code];
	    if (deleg_bit == 1'b1)
	       to_priv = u_Priv_Mode;
	 end
      end
   end

   return to_priv;
endfunction

function MStatus fn_mstatus_upd_on_trap (MStatus mstatus, Priv_Mode from_y, Priv_Mode to_x);
   // xPIE = xIE
   mstatus.pies [to_x] = mstatus.ies [to_x];
   // xIE = 0
   mstatus.ies  [to_x] = 0;

   // xPP = y
   if (to_x == m_Priv_Mode)
      mstatus.mpp = from_y;
   else //if (to_x == s_Priv_Mode)
      mstatus.spp = from_y;

   return mstatus;
endfunction

function Tuple2 #(MStatus, Priv_Mode) fn_mstatus_upd_on_ret (MStatus mstatus, Priv_Mode from_x);

   // Pop the interrupt-enable stack
   // (set xIE = xPIE)
   mstatus.ies [from_x] = mstatus.pies [from_x];

   // Enable interrupt at from_x
   // (set xPIE = 1)
   mstatus.pies [from_x] = 1;

   // Pop the previous privilege mode
   // which empties the one-element stack, revealing the default value
   // (set xPP to U -- or M if U is not supported)

   Priv_Mode to_y;

   // TODO: Make misa an argument
   MISA misa; misa.u = 1'b0;
`ifdef ISA_PRIV_U
   misa.u = 1'b1;
`endif
   Priv_Mode default_pp = ((misa.u == 1'b1) ? u_Priv_Mode : m_Priv_Mode);

   if (from_x == m_Priv_Mode) begin
      to_y = mstatus.mpp;
      mstatus.mpp = default_pp;
   end
   else begin //if (from_x == s_Priv_Mode)
      to_y = mstatus.spp;
      mstatus.spp = default_pp;
   end

   return tuple2 (mstatus, to_y);
endfunction

// ================================================================
// Logical view of csr_mtvec register

typedef enum {DIRECT, VECTORED} MTVEC_Mode
deriving (Bits, Eq, FShow);

typedef struct {
   Bit #(XLEN_MINUS_2) base;
   MTVEC_Mode mode;
} MTVec
deriving (Bits, FShow);

function WordXL mtvec_to_word (MTVec mv);
   return {mv.base,
           1'b0,
           pack (mv.mode)};
endfunction

function MTVec word_to_mtvec (WordXL x);
   return MTVec {base: truncate (x >> 2),
                 mode: unpack (x[0])};
endfunction

// ================================================================
// Logical view of csr_mcounteren register
typedef struct {
   Bit#(1) ir;
   Bit#(1) tm;
   Bit#(1) cy;
} MCounteren
deriving (Bits, FShow);

function WordXL mcounteren_to_word (MCounteren mc);
   return {0,
           mc.ir,
	   mc.tm,
	   mc.cy};
endfunction

function MCounteren word_to_mcounteren (WordXL x);
   return MCounteren {ir: x[2],
                      tm: x[1],
		      cy: x[0]};
endfunction

function MCounteren mcounteren_reset_value;
   return MCounteren {ir: 1'b0,
                      tm: 1'b0,
		      cy: 1'b0};
endfunction

// ================================================================
// MIP and MIE fields (interrupt pending, interrupt enable)

typedef struct {
   Vector #(Num_Priv_Modes, Bit #(1)) eips;
   Vector #(Num_Priv_Modes, Bit #(1)) tips;
   Vector #(Num_Priv_Modes, Bit #(1)) sips;
   } MIP
deriving (Bits, FShow);

typedef struct {
   Vector #(Num_Priv_Modes, Bit #(1)) eies;
   Vector #(Num_Priv_Modes, Bit #(1)) ties;
   Vector #(Num_Priv_Modes, Bit #(1)) sies;
   } MIE
deriving (Bits, FShow);

function WordXL mip_to_word (MIP mip);
   return extend (pack (mip));
endfunction

function MIP word_to_mip (WordXL x);
   return MIP {
      eips: unpack ( {x[11], 1'b0, x[9], x[8]} ),
      tips: unpack ( {x[7] , 1'b0, x[5], x[4]} ),
      sips: unpack ( {x[3] , 1'b0, x[1], x[0]} )
   };
endfunction

function WordXL mie_to_word (MIE mie);
   return extend (pack (mie));
endfunction

function MIE word_to_mie (WordXL x);
   return MIE {
      eies: unpack ( {x[11], 1'b0, x[9], x[8]} ),
      ties: unpack ( {x[7] , 1'b0, x[5], x[4]} ),
      sies: unpack ( {x[3] , 1'b0, x[1], x[0]} )
   };
endfunction

// ================================================================
// MCAUSE (reason for exception)

typedef struct {
   Bit #(1)  interrupt;
   Exc_Code  exc_code;
   } MCause
deriving (Bits);

instance FShow #(MCause);
   function Fmt fshow (MCause mc);
      if (mc.interrupt == 1)
	 return fshow_interrupt_Exc_Code (mc.exc_code);
      else
	 return fshow_trap_Exc_Code (mc.exc_code);
   endfunction
endinstance

function WordXL mcause_to_word (MCause mc);
   return {mc.interrupt, 0, mc.exc_code};
endfunction

function MCause word_to_mcause (WordXL x);
   return MCause {interrupt: msb (x),
		  exc_code:  truncate (x)};
endfunction

// Exception Codes in mcause

typedef Bit #(4) Exc_Code;

// When Interrupt = 1 (interrupt)

Exc_Code  exc_code_USER_SW_INTERRUPT             = 0;
Exc_Code  exc_code_SUPERVISOR_SW_INTERRUPT       = 1;
Exc_Code  exc_code_HYPERVISOR_SW_INTERRUPT       = 2;
Exc_Code  exc_code_MACHINE_SW_INTERRUPT          = 3;

Exc_Code  exc_code_USER_TIMER_INTERRUPT          = 4;
Exc_Code  exc_code_SUPERVISOR_TIMER_INTERRUPT    = 5;
Exc_Code  exc_code_HYPERVISOR_TIMER_INTERRUPT    = 6;
Exc_Code  exc_code_MACHINE_TIMER_INTERRUPT       = 7;

Exc_Code  exc_code_USER_EXTERNAL_INTERRUPT       = 8;
Exc_Code  exc_code_SUPERVISOR_EXTERNAL_INTERRUPT = 9;
Exc_Code  exc_code_HYPERVISOR_EXTERNAL_INTERRUPT = 10;
Exc_Code  exc_code_MACHINE_EXTERNAL_INTERRUPT    = 11;

// When Interrupt = 0 (trap)

Exc_Code  exc_code_INSTR_ADDR_MISALIGNED         = 0;
Exc_Code  exc_code_INSTR_ACCESS_FAULT            = 1;
Exc_Code  exc_code_ILLEGAL_INSTRUCTION           = 2;
Exc_Code  exc_code_BREAKPOINT                    = 3;

Exc_Code  exc_code_LOAD_ADDR_MISALIGNED          = 4;
Exc_Code  exc_code_LOAD_ACCESS_FAULT             = 5;

Exc_Code  exc_code_STORE_AMO_ADDR_MISALIGNED     = 6;
Exc_Code  exc_code_STORE_AMO_ACCESS_FAULT        = 7;

Exc_Code  exc_code_ECALL_FROM_U                  = 8;
Exc_Code  exc_code_ECALL_FROM_S                  = 9;
Exc_Code  exc_code_RESERVED_10                   = 10;
Exc_Code  exc_code_ECALL_FROM_M                  = 11;

Exc_Code  exc_code_INSTR_PAGE_FAULT              = 12;
Exc_Code  exc_code_LOAD_PAGE_FAULT               = 13;
Exc_Code  exc_code_RESERVED_14                   = 14;
Exc_Code  exc_code_STORE_AMO_PAGE_FAULT          = 15;


function Fmt fshow_interrupt_Exc_Code (Exc_Code exc_code);
   return case (exc_code)
	     exc_code_USER_SW_INTERRUPT:             $format ("USER_SW_INTERRUPT");
	     exc_code_SUPERVISOR_SW_INTERRUPT:       $format ("SUPERVISOR_SW_INTERRUPT");
	     exc_code_HYPERVISOR_SW_INTERRUPT:       $format ("HYPERVISOR_SW_INTERRUPT");
	     exc_code_MACHINE_SW_INTERRUPT:          $format ("MACHINE_SW_INTERRUPT");

	     exc_code_USER_TIMER_INTERRUPT:          $format ("USER_TIMER_INTERRUPT");
	     exc_code_SUPERVISOR_TIMER_INTERRUPT:    $format ("SUPERVISOR_TIMER_INTERRUPT");
	     exc_code_HYPERVISOR_TIMER_INTERRUPT:    $format ("HYPERVISOR_TIMER_INTERRUPT");
	     exc_code_MACHINE_TIMER_INTERRUPT:       $format ("MACHINE_TIMER_INTERRUPT");

	     exc_code_USER_EXTERNAL_INTERRUPT:       $format ("USER_EXTERNAL_INTERRUPT");
	     exc_code_SUPERVISOR_EXTERNAL_INTERRUPT: $format ("SUPERVISOR_EXTERNAL_INTERRUPT");
	     exc_code_HYPERVISOR_EXTERNAL_INTERRUPT: $format ("HYPERVISOR_EXTERNAL_INTERRUPT");
	     exc_code_MACHINE_EXTERNAL_INTERRUPT:    $format ("MACHINE_EXTERNAL_INTERRUPT");
	     default:                                $format ("unknown interrupt Exc_Code %d", exc_code);
	  endcase;
endfunction

function Fmt fshow_trap_Exc_Code (Exc_Code exc_code);
   return case (exc_code)
	     exc_code_INSTR_ADDR_MISALIGNED:      $format ("INSTRUCTION_ADDR_MISALIGNED");
	     exc_code_INSTR_ACCESS_FAULT:         $format ("INSTRUCTION_ACCESS_FAULT");
	     exc_code_ILLEGAL_INSTRUCTION:        $format ("ILLEGAL_INSTRUCTION");
	     exc_code_BREAKPOINT:                 $format ("BREAKPOINT");

	     exc_code_LOAD_ADDR_MISALIGNED:       $format ("LOAD_ADDR_MISALIGNED");
	     exc_code_LOAD_ACCESS_FAULT:          $format ("LOAD_ACCESS_FAULT");

	     exc_code_STORE_AMO_ADDR_MISALIGNED:  $format ("STORE_AMO_ADDR_MISALIGNED");
	     exc_code_STORE_AMO_ACCESS_FAULT:     $format ("STORE_AMO_ACCESS_FAULT");

	     exc_code_ECALL_FROM_U:               $format ("ECALL_FROM_U");
	     exc_code_ECALL_FROM_S:               $format ("ECALL_FROM_S");
	     exc_code_ECALL_FROM_M:               $format ("ECALL_FROM_M");

	     exc_code_INSTR_PAGE_FAULT:           $format ("INSTRUCTION_PAGE_FAULT");
	     exc_code_LOAD_PAGE_FAULT:            $format ("LOAD_PAGE_FAULT");
	     exc_code_STORE_AMO_PAGE_FAULT:       $format ("STORE_AMO_PAGE_FAULT");

	     default:                             $format ("unknown trap Exc_Code %d", exc_code);
	  endcase;
endfunction

// ================================================================
// Function from mstatus, mip, mie and current privilege to:
//     whether or not an interrupt is pending,
// and if so, corresponding exception code

function Maybe #(Exc_Code) fn_interrupt_pending (WordXL mstatus, WordXL mip, WordXL mie, Priv_Mode cur_priv);
   Bit #(1) ip = 0;
   Exc_Code exc_code = ?;
   for (Integer j = 0; j < valueOf (Num_Priv_Modes); j = j + 1) begin

      // Interrupts enabled if mstatus [j] is set for cur_priv or higher privs
      Bit #(1) ipj = 0;
      for (Integer k = 0; k < valueOf (Num_Priv_Modes); k = k + 1)
	 if (fromInteger (k) >= cur_priv)
	    ipj = ipj | mstatus [k];

      // Interrupt-pending/enable in mip and mie
      if (ipj == 1) begin
	 // Spec: prioritize external > software > timer
	 Integer j_external = 8;
	 Integer j_sw       = 0;
	 Integer j_timer    = 4;
	 if ((mip [j + j_external] & mie [j + j_external]) == 1)
	    exc_code = fromInteger (j + j_external);
	 else if ((mip [j + j_sw] & mie [j + j_sw]) == 1)
	    exc_code = fromInteger (j + j_sw);
	 else if ((mip [j + j_timer] & mie [j + j_timer]) == 1)
	    exc_code = fromInteger (j + j_timer);
	 else
	    ipj = 1'b0;
      end
      ip = ip | ipj;
   end
   return ((ip == 1) ? tagged Valid exc_code : tagged Invalid);
endfunction

// ================================================================