main :-
bird(Type),
write('It is suggested that the bird is '),
write(Type),
nl,
undo;
write('Unable to find this bird in the knowledge base'),nl,undo.

bird(sparrow) :-

feature(four_inch_length),

feature(thick_conical_bill),

feature(gray_brown_crown),

nl,!.





bird(kingfisher) :-

feature(nineteen_cm_long),

feature(large_beak),

feature(short_tail),

feature(green_crest),

feature(long_stout_dark_bill),

nl,!.





bird(golden_eagle) :-

feature(three_feet),

feature(two_meter_wingspan),

feature(dark_yellowish_brown_color),

nl,!.



bird(cuckoo) :-

feature(thirty_two_cm_length),

feature(white_belly_gray_stripes),

feature(pointed_black_bill),

feature(seventy_six_cm_wingspan),

nl,!.



bird(bald_eagle) :-

feature(feathers_on_leg),

feature(seven_feet_wingspan),

feature(dark_white_color_on_head),

feature(dark_brown_color),

nl,!.

ask(Question) :-
write('Does this bird have this feature'),
write(Question),
write('? :'),
read(Response),
( (Response == yes; Response == y)
->
assert(yes(Question));
assert(no(Question)),fail).
:- dynamic yes/1,no/1.

feature(S) :-
(yes(S)
->
true;
(no(S)
->
fail;
ask(S))).

undo :- retract(yes(_)),fail.
undo :- retract(no(_)),fail.
undo.