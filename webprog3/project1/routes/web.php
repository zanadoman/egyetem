<?php

use Illuminate\Support\Facades\Route;
use App\Http\Controllers\StudentController;

Route::get('/', function () {
    return view('welcome');
});

Route::get('/student', [StudentController::class, 'get']);
Route::post('/student', [StudentController::class, 'add']);
Route::put('/student', [StudentController::class, 'update']);
Route::delete('/student', [StudentController::class, 'delete']);
