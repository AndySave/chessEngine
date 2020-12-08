
#include <bits/stdc++.h>
#include "defenitions.h"


#define fromsq(m) (m & 0x7F)
#define tosq(m) ((m >> 7) & 0x7F)
#define captured(m) ((m >> 14) & 0xF)
#define promoted(m) ((m >> 20) & 0xF)

#define epFlag(m) 0x40000
#define pwnStartFlag(m) 0x80000
#define castleFlag(m) 0x1000000

#define captureFlag(m) 0x7C000
#define promotedFlag(m) 0xF00000


