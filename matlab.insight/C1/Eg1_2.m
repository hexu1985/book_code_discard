% Script Eg1_2
% Minimum of the quadratic x^2 + bx + c on the interval [L,R].

% Acquire and display the input data...
b = input('Enter b:');
c = input('Enter c:');
L = input('Enter L:');
R = input('Enter R (L<R):');
clc
fprintf('Quadratic: x^2 + bx + c,  b = %5.2f, c = %5.2f\n',b,c)
fprintf('Interval : [L,R], L = %5.2f, R = %5.2f\n\n',L,R)
% The critical point...
xc = -b/2;
if xc < L
    % Minimum at the left endpoint...
    fL = L^2 + b*L + c;
    fprintf('Minimizing x    = %5.2f\n',L)
    fprintf('Minimum f value = %5.2f\n',fL)
elseif L <= xc && xc <= R
    % Minimum at the critical point...
    fxc = c - (b/2)^2;
    fprintf('Minimizing x    = %5.2f\n',xc)
    fprintf('Minimum f value = %5.2f\n',fxc)
else
    % Minimum at the right endpoint...
    fR = R^2 + b*R + c;
    fprintf('Minimizing x    = %5.2f\n',R)
    fprintf('Minimum f value = %5.2f\n',fR)
end