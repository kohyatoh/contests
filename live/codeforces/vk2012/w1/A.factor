USING: io kernel math math.parser math.functions sequences ;

  readln string>number
  dup
  3 *
  1 -
  *
  2 /
  floor
  number>string
  print

