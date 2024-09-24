<?php

namespace App\Models;

use Illuminate\Database\Eloquent\Factories\HasFactory;
use Illuminate\Database\Eloquent\Model;

class Student extends Model
{
    use HasFactory;

    public static function getList() {
        return [
            ['neptun' => 'Z17V4D', 'name' => 'Zana Domán'],
            ['neptun' => 'AEEBES', 'name' => 'Plasku Dominik']
        ];
    }
}
