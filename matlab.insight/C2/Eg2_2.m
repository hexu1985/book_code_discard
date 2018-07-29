% Script Eg2_2
% Pi Via Polygons

% Input the iteration parameters...
clc
delta = input('Enter the error tolerance:');
nMax  = input('Enter the iteration bound:');

% The triangle case...
n = 3;                        % Number of Polygon Edges
A_n = (n/2)*sin(2*pi/n);      % Inscribed Area
B_n = n*tan(pi/n);            % Circumscribed Area
ErrorBound = B_n - A_n;       % The error bound

% Iterate while error too big and n sufficiently small...
while (ErrorBound  > delta  && n < nMax)
    n = n+1;
    A_n = (n/2)*sin(2*pi/n);
    B_n = n*tan(pi/n);
    ErrorBound = B_n - A_n;
end

% Display the final approximation...
nStar = n;
rho_nStar = (A_n + B_n)/2;
clc
fprintf(' delta = %10.3e\n nStar = %1d\n nMax  = %1d\n\n',...
                                               delta,nStar,nMax)
fprintf(' rho_nStar = %20.15f\n Pi        = %20.15f\n',...
                                                   rho_nStar,pi)


