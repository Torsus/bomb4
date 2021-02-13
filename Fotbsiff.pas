program fotbsiff(input,output,fotbfil,printfil);
type intfil=file of integer;
var koppling1:intfil;
a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,steg:integer;
printfil,fotbfil:text;
tot,xtot:array[21..240] of integer;
antal:array[21..240,0..10,0..10] of integer;
teck:char;
procedure filkopiering(var fil1:text;var fil2:intfil);
var odds:integer;
tecken:char;
radslut:boolean;
begin
reset(fil1);
rewrite(fil2);
while not eof(fil1) do begin
odds:=0;
tecken:='A';
radslut:=false;
while ((tecken<> ' ') and (not radslut) and (not eof(fil1))) do begin
read (fil1,tecken);
if eoln(fil1) then radslut:=true;
case tecken of
'0':odds:=10*odds;
'1':odds:=10*odds+1;
'2':odds:=10*odds+2;
'3':odds:=10*odds+3;
'4':odds:=10*odds+4;
'5':odds:=10*odds+5;
'6':odds:=10*odds+6;
'7':odds:=10*odds+7;
'8':odds:=10*odds+8;
'9':odds:=10*odds+9;
end;end;begin
write(fil2,odds);
end;end;
close(fil1);
close(fil2);
end;
begin
assign(koppling1,'slask1');
assign(fotbfil,'fotbfil');
assign(printfil,'lpt1');
rewrite(printfil);
filkopiering(fotbfil,koppling1);
reset(koppling1);steg:=0;
for f:=21 to 240 do begin
tot[f]:=0;
xtot[f]:=0;end;
for g:=21 to 240 do begin
for h:=0 to 10 do begin
for i:=0 to 10 do begin
antal[g,h,i]:=0;end;end;end;
for i:=1 to 10541 do begin
read(koppling1,a,b,c,d,e);
if (abs(100/a+100/b+100/c-1.25)>0.007) or ((a+b+c) mod 5<>0)
then writeln(printfil,a,b,c);
a:=a div 5;b:=b div 5;c:=c div 5;
tot[a]:=tot[a]+1;
xtot[b]:=xtot[b]+1;
tot[c]:=tot[c]+1;
if e>d then
antal[c,e,d]:=antal[c,e,d]+1
else if d=e then
antal[b,d,e]:=antal[b,d,e]+1
else
antal[a,d,e]:=antal[a,d,e]+1
end;
close(koppling1);
write('Matchens nr samt odds? ');
readln(j,k,l,m);
k:=k div 5;l:=l div 5;m:=m div 5;
writeln(printfil,'Matchen':30,j:2,' (',tot[k],' ',xtot[l],' ',tot[m],')');
writeln(printfil);
for n:=0 to 10 do begin
for o:=0 to 10 do begin
if(antal[k,n,o]>1) and
(n>o) then begin
writeln(printfil,n:10,'-',o,' ',tot[k]/antal[k,n,o]:5:2);steg:=steg+1;
end
else if (antal[l,n,o]>1) and
(n=o) then begin writeln(printfil,n:10,'-',o,' ',xtot[l]/antal[l,n,o]:5:2);
steg:=steg+1;end
else if (antal[m,o,n]>1) and
(o>n) then begin
writeln(printfil,n:10,'-',o,' ',tot[m]/antal[m,o,n]:5:2);steg:=steg+1;
end;
end;end;
end.
