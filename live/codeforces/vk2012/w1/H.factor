USING: io kernel math math.parser math.functions sequences ;

IN: template

: tolower ( n -- answer )
    dup
    97 <
    [
      65 -
      97 +
    ]
    [ ]
    if
;
: toupper ( n -- answer )
    dup
    97 <
    [ ]
    [
      65 +
      97 -
    ]
    if
;

  0
  readln
  [
    swap
    0 =
    [
      toupper
      1
      swap
    ]
    [
      tolower
      0
      swap
    ]
    if
  ]
  map
  print
  drop
