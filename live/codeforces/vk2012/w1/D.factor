USING: io kernel math math.parser math.functions sequences ;

  readln
  [
    dup
    48 < 
    [ 1 1 = ]
    [
      dup
      57 >
    ]
    if
    nip
  ]
  filter
  print
