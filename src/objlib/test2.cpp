/*
    Software License Agreement (BSD License)
    
    Copyright (c) 1997-2011, David Lindauer, (LADSoft).
    All rights reserved.
    
    Redistribution and use of this software in source and binary forms, 
    with or without modification, are permitted provided that the following 
    conditions are met:
    
    * Redistributions of source code must retain the above
      copyright notice, this list of conditions and the
      following disclaimer.
    
    * Redistributions in binary form must reproduce the above
      copyright notice, this list of conditions and the
      following disclaimer in the documentation and/or other
      materials provided with the distribution.
    
    * Neither the name of LADSoft nor the names of its
      contributors may be used to endorse or promote products
      derived from this software without specific prior
      written permission of LADSoft.
    
    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
    AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, 
    THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR 
    PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER 
    OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, 
    EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, 
    PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; 
    OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, 
    WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR 
    OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
    ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

    contact information:
        email: TouchStone222@runbox.com <David Lindauer>
*/
#include "ObjFactory.h"
#include "ObjIeee.h"
#ifdef XXXXX
#include "LinkPartition.h"
#include "LinkAttribs.h"
#include "LinkExpression.h"
#include "LinkLibrary.h"
#include "LinkManager.h"
#include "LinkMap.h"
#include "LinkOverlay.h"
#include "LinkPartition.h"
#include "LinkRegion.h"
#include "LinkRegionFileSpec.h"
#include "LinkRemapper.h"
#include "LinkTokenizer.h"
#include "CmdSwitch.h"
#endif
#include <cstdio>
#include <iomanip>

int main()
{
    

    ObjIeeeIndexManager im1;
    ObjFactory fact1(&im1);
    FILE *b = fopen("bzip2.o", "r");
    FILE *c = fopen( "q.o" , "w");
    ObjIeee i1("hi");
    ObjFile *fi1 = i1.Read(b, ObjIeee::eAll, &fact1);
    i1.Write(c, fi1, &fact1);
        
}