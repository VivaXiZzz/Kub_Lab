n_total = 400
X = linspace(-0.3, 0.3, n_total);

Noise=0.1*rand(1,(n_total)); 
Y=cos(3*X-15)./abs(X)+Noise;

hold on; 
plot(X,Y,'LineStyle','none','Marker','.','MarkerSize',5); 
Net = feedforwardnet(16,'traingdx'); 
Net=train(Net,X,Y); 
X_rez=-0.4:0.0012:0.4; 
Y_rez = sim(Net, X_rez); 
plot(X_rez,Y_rez,'LineStyle','none','Marker','.','MarkerSize',15); 
hold off; 