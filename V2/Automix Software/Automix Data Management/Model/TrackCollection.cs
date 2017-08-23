using System;
using System.Collections.Generic;
using System.ComponentModel;

namespace AutomixDataManagement.Model
{
    public class TrackCollection : List<Track>
    {
        public static TrackCollection CopyFrom(TrackCollection old)
        {
            TrackCollection newCollection = new TrackCollection();
            foreach (Track t in old)
            {
                newCollection.Add(Track.CopyFrom(t));
            }
            return newCollection;
        }

        public void ExportToMP3(BackgroundWorker bw, string outputFile)
        {
            //IExportation exportEngine = new SmoothMix();
            //exportEngine->exportMix(bw, this, outputFile);
        }

        public void ExportToText(string outputFile)
        {
            AudioIO.TextExport(this, outputFile);
        }

        public void SafeAdd(Track track)
        {
            if (!IsPresent(track) && !string.IsNullOrEmpty(track.Checksum))
            {
                Add(track);
            }
        }

        public bool IsPresent(Track track)
        {
            foreach (Track t in this)
            {
                if (track.Checksum.Equals(t.Checksum) || track.Checksum.Equals(t.Checksum))
                {
                    return true;
                }
            }
            return false;
        }

        public Track Search(string name)
        {
            foreach (Track t in this)
            {
                if (t.Name.Equals(name))
                {
                    return t;
                }
            }
            return null;
        }

        public void Remove(string name)
        {
            Track temp = Search(name);
            if (temp != null)
            {
                Remove(temp);
            }
        }

        public void Purge()
        {
            RemoveAll(t => t.Duration == 0 || string.IsNullOrEmpty(t.Checksum));
        }

        public void Concat(TrackCollection original)
        {
            foreach (Track t in original)
            {
                SafeAdd(t);
            }
        }
    }
}
