% Script Eg2_1
% Pi Via Tiling

% Enter the disk radius...
clc
n = input('Enter an  integral radius n: ');

% Tile just the first quadrant, then multiply by four...
N1 = 0;
for k = 1:n
    % Add in the number of uncut tiles in row k...
    m = floor(sqrt(n^2 - k^2));
    N1 = N1 + m;
end

% Display the estimate...
rho_n = 4*N1/n^2;
clc
fprintf('n      = %1d\n',n)
fprintf('rho_n  = %12.8f\n',rho_n)
fprintf('Error  = %12.8f\n',abs(pi-rho_n))