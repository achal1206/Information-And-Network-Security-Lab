BEGIN{
drop=0;
}
{
if($1=="d" )
 {
 drop++;
 }
}
END{
printf("Total number of %s packets dropped due to congestion =%d\n",$5,drop);
}
//OUTPUT:
//Total number of ping packets dropped due to congestion =19876
