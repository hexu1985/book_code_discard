% Script Eg3_1A
% Rational Approximation of pi
% Assumes that the numerator/denominator limit M is initialized.

% Initializations...
pBest = 1;                      % Best numerator ``found so far''
qBest = 1;                      % Best denominator ``found so far''...
err_pq = abs(pBest/qBest - pi); % Error in current best fraction...

% Check out all possible denominators...
for q = 1:M
    % Initializations for the p-search...
    p0 = 1;
    e0 = abs(pi - p0/q);
    % For this q, find the best numerator p0...
    for p=1:M
        if abs(pi - p/q) < e0
            % A new best numerator has been found for this q...
            p0 = p;
            e0 = abs(pi - p/q);
        end
    end
    % Check to see if we have a new best quotient for this q...
    if  e0 < err_pq
        pBest = p0;
        qBest = q;
        err_pq = e0;
    end
end
MyPi = pBest/qBest;

