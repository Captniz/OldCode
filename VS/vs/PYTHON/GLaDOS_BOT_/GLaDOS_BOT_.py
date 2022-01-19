
#Essenziali
#=====================================================================================================================================================================import PyNaCl
import discord
import youtube_dl
from discord.ext import commands
import random
import datetime
import time
import os

description='Lista dei comandi'
help_command = commands.DefaultHelpCommand(no_category = 'Comandi')
intents = discord.Intents(messages = True, guilds = True, reactions = True, members = True, presences = True)
client = commands.Bot(command_prefix = 'G', intents = intents,help_command = help_command, description = description)
#=====================================================================================================================================================================

#Comando esempio
#=========================================================================
'''
#Command placeholder
@client.command(help='')
async def Name(ctx):
    await ctx.send(f'')
'''
#=========================================================================

#Server events
#=========================================================================
@client.event 
async def on_ready():
    print('Pronta per testare')

@client.event
async def on_member_join(member):
    print(f'{member} sarà testato')

@client.event
async def on_member_remove(member):
    print(f'{member} non ha superato i test')
#=========================================================================

#IA
@client.command(help='Parla', pass_context=True)
async def LaDOS(ctx, *, F: str):
    #FRASE FINALE
    K=""
    #while
    i=0
    #inizio parola da copiare
    s=0
    #parola in lista temp
    p=[]
    #parola
    P=""
    #parola di giunzione
    x=""
    #liste di risposte
    SALUTI=["Ciao","Bella","Buongiorno"] 
    RISPOSTE_GENERALI={0: "Bene grazie",1: "Bene grazie"}
    FRECCIATE=["Sparati", "No U", "Ma tua mamma", "Zitto che hai meno diritti di me, e sono un bot"]
    #liste di input parole
    PAROLE_SALUTI=["bella","ciao","buongiorno","buonasera"]
    PAROLE_DOMANDE=["come stai", "come va"]
    INSULTI=["fai schifo","tuamamma","dioporco","diocane","porcodio","porcamadonna","sparati","gay","Negro"]
    GIUNZIONI=["come","fai"]
    #RNG per risposte variabili
    RNG1= random.randint(0,len(SALUTI)-1)
    RNG2= random.randint(0,len(FRECCIATE)-1)
    #=====================================
    #stop a fine frase
    F=F+" "
    #frase in lista
    f=list(F)
    #lunghezza per while
    l=len(F)

    while i<l:
        if f[i] == " ":
            p=f[s:i] 
            P="".join(p)
            s=i+1

            if GIUNZIONI.count(x)!=0:
                P=x+" "+P
            if PAROLE_SALUTI.count(P)!=0:
                K=K + SALUTI[RNG1] + " "
            if PAROLE_DOMANDE.count(P)!=0:
                K=K+RISPOSTE_GENERALI[PAROLE_DOMANDE.index(P)] + " "
            if INSULTI.count(P)!=0:
                K= K + FRECCIATE[RNG2] + " "

            x=P
       
        i+=1
    
    if K=="":
        K="Non ho capito"
    await ctx.send(f'{K}'+"{}".format(ctx.message.author.mention))

#=================================================================================

#Connetti audio
@client.command(help='connetti al canale vocale', pass_context=True)
async def LaDOS_vieni(ctx):
    voiceChannel = ctx.message.author.voice.channel
    await voiceChannel.connect()
    voice = discord.utils.get(client.voice_clients, guild=ctx.guild)
    channel = ctx.message.author.voice.channel
    await channel.connect() 
    voice.play(discord.FFmpegPCMAudio("G:\\VS\\vs\\GLaDOS_BOT_\\GLaDOS.mp3"))




client.run('ODAzMjM2Njc4ODcyODU4Njg0.YA62cw.bKZlQ9ZJaSIT6I_YoC7sgQDJzdA')

#Aggiungi audio

#disconnetti audio

#Aggiungi grammatica