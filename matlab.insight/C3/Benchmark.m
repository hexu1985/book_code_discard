% Script Benchmark
% Compares the efficiency of the scripts Eg3_1A and FasterEg3_1A.
% Eg3_1A is Eg3_1 without input and output commands.
% FasterEg3_1A is FasterEg3_1 without input and output commands.

% Clear the command window and acquire M...
clc
M = input('Enter M:');

% Benchmark Eg3_1...
tic
Eg3_1A
T1 = toc;

% Benchmark FasterEg3_1...
tic
FasterEg3_1A
T2 = toc;

% Report the results...
clc
timeRatio = T1/T2;
fprintf('M = %1d\n',M)
fprintf('Eg3_1 Time / FasterEg3_1 Time = %10.1f\n',timeRatio)