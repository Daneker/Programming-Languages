cartesian( [], X, [] ).
cartesian( [ F | R ], X, Y ) :- product( F, X, Y1 ), 
				cartesian( R, X, Y2 ), 
				append( Y1, Y2, Y ).

product( X, [], [] ).
product( X, [ F | R ], [ pair( X, F ) | Y ] ) :- product( X, R, Y ).

deepmember( X, [ X | R ] ).
deepmember( X, [ F | R ] ) :- deepmember( X, F ).
deepmember( X, [ F | R ] ) :- deepmember( X, R ).

notcontains( X, [] ).
notcontains( X, [ F | R ] ) :- X \= F, notcontains( X, R ).

inserthead( [ H | T ], X, [ H | L ] ) :- .

% inserttail( [], X, [ X ] ).
% inserttail( [ H | T ], X, [ H | L ] ):- inserttail( T, X, L ).

addunique( X, L1, L2 ) :- notcontains( X, L1 ), L2 = [ X | L1 ].

setinsertion( X, S1, S2 ) :- ( member( X, S1 ), S2 = S1 );
			     ( addunique( X, S1, S3 ), S2 = S3 ).

graph1( [ [ 1, 2 ], [ 1, 3 ], [ 2, 3 ], [ 3, 4 ], [ 4, 1 ] ] ).
graph2( [ [ 1, 2 ], [ 2, 3 ], [ 2, 4 ], [ 3, 4 ],
	[ 4, 3 ], [ 3, 1 ], [ 4, 1 ] ] ).
graph3( [ [ 1, 2 ], [ 1, 3 ], [ 2, 3 ], [ 3, 2 ],
	[ 3, 4 ], [ 2, 4 ], [ 4, 6 ], [ 4, 5 ],
	[ 5, 6 ], [ 6, 5 ], [ 6, 7 ], [ 5, 7 ],
	[ 7, 1 ] ] ).


allvertices( [], [] ).
allvertices( [[F1, F2] | R], L ) :- allvertices( R, Z1 ), 
					setinsertion( F1, Z1, Z2 ), 
					setinsertion( F2, Z2, L ).

connected( V0, V1, [[F1, F2] | R ] ) :- ( V0 = F1, V1 = F2 );
					connected( V0, V1, R ).

path( G, B, 1, F, [ B ], B ).
path( G, B, N, F, [ B | P ], L ) :-  N > 1,
				N1 is N - 1,
				connected( B, Z, G ),
				notcontains( Z, F ),
				path( G, Z, N1, [ Z | F ], P, L ).  	
 
hamiltoniancircuit( G, C ) :-
				allvertices( G, Vert ),
				Vert = [ V0 | _ ],
				length( Vert, N ),
				path( G, V0, N, [ V0 ], C, LastV ),
				connected( LastV, V0, G ).




   
