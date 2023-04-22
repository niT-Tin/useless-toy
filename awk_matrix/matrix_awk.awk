{ RAINLENGTH = int($1 * 3 / 5)
  letters="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789@#$%^&*()"; 
  if (rl[$3] == 0)
    rl[$3] = RAINLENGTH;
  # 获取对应位置的字符
  letter=substr(letters, $4, 1);
  # 初始计算需要打印空白符的位置
  l[$3] = ( a[$3] - rl[$3] >= 0 ? a[$3] - rl[$3] : a[$3] );
  for (x in a) {
    if (a[x] == rl[x] && isr[x] == 0) {
      isr[x]=1
    }
    if (isr[x]) {
      printf "\033[%s;%sH\033[2;30m%s",l[x], x," ";
    } 
    o=a[x];
    a[x]=a[x]+1;
    printf "\033[%s;%sH\033[2;32m%s",o,x,letter; 
    printf "\033[%s;%sH\033[1;37m%s\033[0;0H",a[x],x,letter;
    l[x] = ( a[x] - rl[x] >= 0 ? a[x] - rl[x] : a[x] );
    if (a[x] >= $1 + rl[x]) { 
      # a[x]=0;
      delete a[x];
      srand();
      rl[x] = int(rand() * $1 / 2);
      isr[x]=0;
    } 
  }
}
