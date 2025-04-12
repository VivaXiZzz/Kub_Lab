n_total = 1200;
n_half = n_total / 2;

x1 = linspace(-10, -0.3, n_half);

x2 = linspace(0.3, 10, n_half);

X = [x1, x2];

Noise=0.2*rand(1,(n_total)); 
Y=cos(3*X-15)./abs(X)+Noise;

hold on; 
% визуализируем обучающую выборку 
plot(X,Y,'LineStyle','none','Marker','.','MarkerSize',5); 
% создаем ИНС 
Net = feedforwardnet(32,'traingdx'); 
% обучаем ИНС 
Net=train(Net,X,Y); 
% Тестируем ИНС на интервале шире, чем обучающая выборка 
X_rez=-12:0.012:12; 
Y_rez = sim(Net, X_rez); 
% визуализируем результаты аппроксимации 
plot(X_rez,Y_rez,'LineStyle','none','Marker','.','MarkerSize',15); 
hold off; 