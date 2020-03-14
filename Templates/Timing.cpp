const clock_t begin_time = clock();

float timeDuration = float(clock() - begin_time) / CLOCKS_PER_SEC;
cout << "Time: " << timeDuration << "s" << endl;
