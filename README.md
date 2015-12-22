# time_t
Simple timestamp converter functions. Based on Minix gmtime and mktime code.

# Usage
```Pawn
new year, month, day, hour, minute, second;
gmtime(gettime(), year, month, day, hour, minute, second);
printf("%02d:%02d:%02d %02d.%02d.%04d", hour, minute, second, day, month, year);
```

```Pawn
new timestamp = mktime(2015, 11, 23, 01, 18, 04);
printf("%d", timestamp);
```
