<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;
use Illuminate\Support\Facades\Auth;

class LoginController extends Controller
{
    public function store(Request $request)
    {
        if (Auth::attempt($request->validate([
            'email' => ['string', 'required'],
            'password' => ['string', 'required']
        ]))) {
            $request->session()->regenerate();
            return redirect()
                ->route('messages.index')
                ->with('success', 'Logged in.');
        }
        return redirect()
            ->back()
            ->withErrors('Invalid credentials.');
    }

    public function destroy(Request $request)
    {
        Auth::logout();
        $request->session()->invalidate();
        $request->session()->regenerateToken();
        return redirect()
            ->route('authentication')
            ->with('success', 'Logged out.');
    }
}
